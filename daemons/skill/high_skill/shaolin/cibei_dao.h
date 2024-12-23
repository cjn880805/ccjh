SKILL_BEGIN(CScibei_dao);

virtual void create()
{
	set_name( "�ȱ���");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N����$wбָ��һ�С�ͣ����·��������һ�٣�һ����$n��$l��ȥ",
			120, -10, 0, 0,},
		{"$Nһ�С�ͯ�ӹһ�������������㣬$wһ��һ�գ�ƽ�л���$n�ľ���",
		130, -10, 5, 8,},
		{"$Nչ���鲽������Ծ�䣬һ�С��ƴ����¡�������һ������ն��$n",
		140, -5, 15, 16,},
		{"$Nһ�С����ż�ɽ����$w�󿪴��أ����϶��»���һ���󻡣���ֱ����$n",
		160, 5, 25, 24,},
		{"$N����$wһ����һ�С���Ϫ���㡹��˫�ֳ����������У�����$n���ؿ�",
		180, 10, 30, 33,},
		{"$N����$w��ʹ��һ�С��Ź����ġ����������ã����ҿ�����������$n",
		210, 15, 35, 42,},
		{"$Nһ�С��������ۡ������Ծ����أ�$w˳����ǰ��Ю��������$n��$l",
		240, 5, 50, 51,},
		{"$N����פ�أ�һ�С�������Ϣ�����ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ",
		280, 20, 60, 60,},
		};
	
	int level = me->query_skill("cibei_dao", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("��ʹ�õ��������ԡ�");
	
	if (me->query("hp") < 50)
		return notify_fail("��������������ȱ�����");

	me->receive_damage("hp", 25);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("�������������");

	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry";}
virtual int valid_combine(string combo) { return combo=="fumo_jian"; }

SKILL_END;