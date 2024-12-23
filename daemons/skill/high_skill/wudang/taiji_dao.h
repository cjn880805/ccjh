// taiji-dao.c ̫����

SKILL_BEGIN(CStaiji_dao);

virtual void create()
{
	set_name( "̫����");
	set("valid_force", "taiji_shengong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ", 120, -10, 5, 15, 0,},
		{"$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���", 120, -10, 5, 15, 10,},
		{"$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n", 140, -5, 5, 25, 20,},
		{"$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n", 160, 5, 5, 30, 30,},
		{"$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�", 180, 10, 5, 35, 40,},
		{"$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n", 210, 15, 15, 45, 50,},
		{"$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l", 240, 5, 15, 50, 55,},
		{"$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ", 280, 20, 10, 60, 60,},
	};

	int level = me->query_skill("taiji_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{

	if (me->query("max_mp") < 100)
		return notify_fail("�������������");
	
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("���̫���񹦻��̫ǳ��");
	
	if (me->query_skill("taiji_quan", 1) < 20)
		return notify_fail("���̫��ȭ���̫ǳ��");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("�������������̫��������");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
