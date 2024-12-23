// yunlong_bian.c �����޷�

SKILL_BEGIN(CSyunlong_bian);

virtual void create()
{
	set_name( "�����޷�");

	
	Magic_t * magic;

	magic = add_magic("chan", do_chan);
	magic->name = "���־�";
	magic->mp = 50;
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
		{"$N����һ�һ�С�����ٵء�������$w���ñ�ֱ����׼$n��ͷ����", 100, 10, 10, 0,},
		{"$N����һת��һ�С������ĺ���������$w��������ڿ�һ���͵ػ���$n̫��Ѩ", 150, 10, 20, 10,},
		{"$N৵�һ�����ޣ�һ�С�������ˮ��������$w���ñ�ֱ������$n˫��", 200, 30, 30, 20,},
		{"$N������ң�һ�С����Ƽ��ա�������$w��������Ӱ����ɽ������ɨ��$nȫ��", 200, 40, 40, 30,},
		{"$N��������һ�С���ɽ��ʯ��������$w��һ��ͭ����ֱ����$n", 250, 50, 50, 40,},
		{"$N����һ�ӣ�һ�С����Χ����������$wֱ����$n����", 300, -20, 60, 50,},
		{"$N�߸�Ծ��һ�С���Į���̡�������$w��ֱ��$n��ͷ����", 350, -50, 70, 60,},
	};

	int level = me->query_skill("yunlong_bian", 1);

	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < level)
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

	if( me->query("max_mp") < 200 )
		return notify_fail("����������㣬û�а취�������޷�, ����Щ���������ɡ�");

	if (me->query_skill("force", 1) < 40)
		return notify_fail("��Ļ����ڹ����̫ǳ��");
	
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
		return notify_fail("������������������޷���");
	me->receive_damage("hp", 5);
	return 1;
}

//perform 
static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;
	string msg;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	if( ! target ||	! me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");

	if( me->query_skill("yunlong_bian",1) < 50)
		return notify_fail("��ġ������޷�������̫ǳ��ʹ���ˡ������־���");

	if( me->query("mp") < 50)	//add by Lanwood 2000-12-25
		return notify_fail("����������㡣");

	msg = "$Nʹ�������޷��������־������ӳ�����ͼ��$n��ȫ���ס��\n";
	
	if( random(me->query_combat_exp()) > target->query_combat_exp()/4 )
	{
		msg += "���$p��$P���˸����ֲ�����";
		target->start_busy( me->query_skill("yunlong_bian") / 30 + 1);
		me->start_busy(1+ random(2));
	} 
	else 
	{
		msg += "����$p������$P����ͼ����û���ϵ���" ;
		me->start_busy(4);
	}

	me->add("mp", -50);
	message_vision(msg.c_str(), me, target);
    return 1;
}

SKILL_END;
