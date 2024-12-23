//riyue_bian.h ���±޷�

SKILL_BEGIN(CSriyue_bian);

virtual void create()
{
	set_name( "���±޷�");

	Magic_t * magic;

	magic = add_magic("chan", do_chan);
	magic->name = "���ƾ�";
	magic->mp = 50;
	magic->target = CAST_TO_OTHER;
	magic->valid_cast = CAST_IN_COMBAT;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge,  damage, lvl;
	}action[8] = {
		{"$N����������һ�С���ʯʽ��������$w���ñ�ֱ����׼$n���ظ�Ҫ����������",
			-10,100, 0,},
		{"$N����һת��һ�С��ϴ�ʽ��������$w��������ڿ�һ���͵���$n��ͷ����",
		-20,200, 60,},
		{"$N������ң�һ�С�����ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		-40,300,90,},
		{"$N������ң�һ�С��ֺ�ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		-50,400,100,},
		{"$N������ң�һ�С��ѿ�ʽ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		-60,500, 110,},
		{"$N������ң�һ�С�������ա�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		-60,600,120,},
		{"$N������ң�һ�С���շ�ħ��������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		-70,700,130,},
		{"$N������ң�һ�С����ޱߡ�������$w��������Ӱ����ɽ������ɨ��$nȫ��",
		100,800,200,},
	};
 
  	int level = me->query_skill("riyue_bian", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "whip") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if( me->query("max_mp") < 500 )
		return notify_fail("����������㣬û�а취�����±޷�, ����Щ���������ɡ�");

	if (me->query_skill("hunyuan_yiqi", 1) < 50)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");

	if ( ! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip") )
		return notify_fail("�㻹û�ﵽ�ޱ�ʤ�б޵ľ��磬������ʵ���ñ�����ϰ�ɡ�");

	return 1;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("���±ޱ��������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("�㻹û�ﵽ�ޱ�ʤ�б޵ľ��磬������ʵ���ñ�����ϰ�ɡ�");

	if (me->query("hp") < 50)
		return notify_fail("����������������±޷���");

	me->receive_damage("hp", 5);
	return 1;
}

static int do_chan(CChar * me, CContainer * ob)
{
	CChar * target = NULL;

	if(ob && ob->is_character())
		target = (CChar *)ob;

	CContainer * weapon;
	string msg;

	if( !target || !me->is_fighting(target) )
		return notify_fail("ǣ�ƹ���ֻ�ܶ�ս���еĶ���ʹ�á�");

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("��ʹ�õ��������ԡ�");
		
	if( me->query_skill("riyue_bian",1) < 50)
		return notify_fail("��ġ����±޷�����ûѧ���ң��ò��ˡ������־���");

	if(DIFFERSTR(me->querystr("family/family_name"), "������") && me->querymap_temp("biwu"))
	return notify_fail("ʦ�����������ڴ˴α����в���ʹ�÷Ǳ����书��");
	
	if( target->is_busy() )
		return notify_fail("%sĿǰ���Թ˲�Ͼ���ŵ������ɡ�", target->name());

	if(me->query("mp") < 50)
		return notify_fail("�������������");
	
	me->add("mp", -50);

	msg = "$Nʹ�����±޷������ơ���������������ͼ��$n��ȫ�����������\n";

	if( random(me->query_combat_exp()) > target->query_combat_exp()/2 ) 
	{
		msg += "���$p��$P���˸����ֲ�����";
		target->start_busy( me->query_skill("riyue_bian") / 20 + 2);
		me->start_busy(2);
	} 
	else 
	{
		msg += "����$p������$P����ͼ����û���ϵ���";
		me->start_busy(4);
	}

	message_vision(msg.c_str(), me, target);
	return 1;
}

SKILL_END;

