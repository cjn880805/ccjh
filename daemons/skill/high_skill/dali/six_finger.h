//six_finger.h ������
//lanwood 2001-01-04

SKILL_BEGIN(CSsix_finger);

virtual void create()
{
	set_name( "������");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("�����񽣱������������ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge,  damage;
	}action[6] = {
		{ "$N����������˫��Ĵָͬʱ����������������죬�����̽�������ʯ���쾪���������֮�ƣ���ָ$n���к�$l",
			350,  50, 500,},
		{ "$Nʳָ����������԰ת������������һ����һ���Ĵ̳�������Ѹ�٣����ɻ��ã������ݺᣬ$n�����޷�������·",
			400,100, 400,},
		{ "$N������ָһ�������г彣����ǰ�̳��������ĵ�����Ȼ���죬���ν���ֱָ$n��$l",
		350, 40, 500,},
		{ "$N��������ָ��������س彣����·׾�͹��ӣ�һ���ۻ�������ĵ�����������ɽ��������$nӿȥ",
        350, 60, 500,},
		{ "$N����Сָһ�죬һ���������ٳ�Ѩ�м�������������󽣡�������磬ָ��$n��$l",
		350,  50,  500,},
		{"$N���ַ�ָ��Сָ������������ٳ�Ѩ���������������󽣡�������䣬��$n���벻���ķ������$n��$l",
        350, 40, 500,},
	};
 
  	if (random(me->query_skill("six_finger",1)) > 60 &&
			me->query_skill("kurong_changong",1) > 60 &&
			me->query("mp") > 100)
	{
		me->add("mp", -100);
		m_actions.set("action", "$HIC$N��Ȼ���ý����е���·����һһӿ����ͷ��ʮָ�׵�����ȥ�����������޾��������ݺᣬ����������·������ת��ʹ��$n��ʱ������ң�����ȫ������ʹ��������Ѫ�����ϱ������ʹ̧ͷһ����һ������ӭ���ֵ�");
		m_actions.set("damage", 500);
		return &m_actions;
	}

	int level = random(6);
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	if(me->query_temp("apply/��_����"))
		m_actions.set("damage", (me->query_temp("apply/��_����")+100) * action[level].damage/100);
	else
		m_actions.set("damage", action[level].damage);
						
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
           return notify_fail("�������񽣱�����֡�");
    if (me->query("max_mp") < 1200)
           return notify_fail("�������̫�����޷�ѧ�����񽣡�");
    if (me->query_skill("kurong_changong",1) < 120)
           return notify_fail("��Ŀ�������̫�ͣ��޷�ѧ�����񽣡�");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 50)
           return notify_fail("�������̫���ˡ�");
    if (me->query("mp") < 50)
           return notify_fail("������������������񽣡�");
    
    me->receive_damage("hp", 40);
    me->add("mp", -30);
    return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}

	if( random( damage / 2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return "��������������һ�����죬���Ͼ�����һЩѪ�Σ�";
	}

	return 0;
}

SKILL_END;

