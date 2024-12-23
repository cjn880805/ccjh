//hujia_daofa.h ���ҵ���

SKILL_BEGIN(CShujia_daofa);

virtual void create()
{
	set_name( "���ҵ���");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge, parry, lvl, damage;
	}action[8] = {
		{"$N����$w���ƣ�һ�С��Ʋ�������������������$nl��ȥ  ",
			80, -10, 10, 0, 25,},
		{"$Nһ�С�ɳŸ�Ӳ������������¶��ϻ��˸��뻡��$wһ��һ�գ�ƽ�л���$n�ľ���  ",
        100, 5, 10, 8, 30,},
		{"$Nʹ��һ�С���������������$w��������һ��ѹ��$n ",
        120, 10, 10, 16, 35,},
		{ "$Nһ�С��������ȡ���$w������б����$n��ȥ ",
		150, 5, 10, 24, 40,},
		{ "$N����$w��ת��Ծ��һ�С���´��ʡ���һ���׹�����$n���ؿ� ",
		200, -5, 5, 32, 45,},
		{"$N����$w��ʹ��һ�С��׺���᡹���������ã����ҿ�����������$n  ",
			230, 10, 5, 40,50,},
		{"$Nһ�С�������ů�������Ծ����أ�$w˳����ǰ��Ю��������$n��$l  ",
        300, 5, 10, 48, 60,},
		{ "$Nļ��ʹһ�С��˷��ص�������ʱ�����������䵶��������˷�ӿ��$nȫ��  ",
        320, 10, 20, 56, 70,},
	};

  	int level = me->query_skill("hujia_daofa", 1);
	for(int i = 8; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
	
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
			
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");

	if (me->query_skill("force", 1) < 20)
		return notify_fail("��Ļ����ڹ����̫ǳ��");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	if (me->query("hp") < 50)
		return notify_fail("������������������˺��ҵ�����");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;

