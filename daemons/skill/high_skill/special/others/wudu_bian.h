// wudu-bian.c �嶾�޷�
SKILL_BEGIN(CSwudu_bian);

virtual void create()
{
	set_name( "�嶾�޷�");

	Magic_t * magic;

	magic = add_magic("judu", do_judu);
	magic->name = "�۶���";
	magic->mp = 20;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[] = {
		{"$N�ᶶ����һ�С�������о��������$w���ñ�ֱ��ֱ��$n��ȥ", 60, 30, 30, 0,},
		{"$N����һת��һ�С���Ы��β����$w�ڿ���ת�˸�Ȧ���Թ���ĽǶ�����$n", 150, -20, 50, 10,},
		{"$Nһ�����ޣ�һ�С�������˿��������$w����������Ӱ������$n", 200, 30, 60, 20,},
		{"$N������ң�һ�С���ܳ�����������$w������ң�ֱ����$n�ؿ�", 300, 10, 80, 30,},
		{"$N��������һ�С���򼷭��������$wת��������ȦȦ������һ�����磬ֱ��$n��ȥ", 500, -20, 150, 40,},
	};


	int level = me->query_skill("wudu_bian", 1);

	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level )
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="whip" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if( me->query_skill("wudu_xinfa") < 30 )
		return notify_fail("����嶾�ķ�̫�ͣ��������嶾�ޡ�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("���������һ�����Ӳ������޷���");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("��������������嶾�޷���");
	me->receive_damage("hp", 25);
	return 1;
}

static int do_judu(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( me->query_skill("wudu_bian",1) < 60 
		||me->query_skill("wudu_xinfa",1) < 50 )
		return notify_fail("����嶾�ķ�����̫ǳ���޷��۶���");

	if( !target ||! me->is_fighting(target) )
		return notify_fail("��ֻ�ܶ�վ���еĶ��־۶���");

	if( target->is_busy() )
		return notify_fail("%s�Ѿ���æ�����ˣ�����Ҫ���ö��ˡ�", target->name());

	if( me->query("mp") < 20)		//add by Lanwood 2000-12-25
		return notify_fail("����������㡣");

	me->start_busy(1);
	
	msg = "$NĬ�����������������ڱ��ϣ�ֻ��һ����ɫ��������ס�˳��ޡ�";

	if  ( random(me->query_combat_exp() + 1) > target->query_combat_exp()/2 
	    && random(me->query_skill("wudu_xinfa",1)) >20) 
	{
		msg += "$n�벻������������Ⱦ������";
		target->receive_damage("hp", me->query_skill("wudu_xinfa",1));
        target->receive_wound("hp",15 + random(10));
		target->apply_condition("wudu_poison", random(me->query_skill("wudu_xinfa",1)/10) + 1 +
						target->query("condition/wudu_poison"));
		target->start_busy(1 + random(2)); 
		
	}
	else
	{
		msg += "����$n������$N�Ķ��ƣ�������ס������û���ж���";
	}

	me->add("mp", -20);

	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;

