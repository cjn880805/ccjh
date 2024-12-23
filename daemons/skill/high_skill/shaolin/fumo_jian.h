SKILL_BEGIN(CSfumo_jian);

virtual void create()
{
	set_name( "��ħ��");
	set("valid_force", "hunyuan_yiqi");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$Nһʽ�������ơ�������ƽָ��������磬һ���ǳɺ�ɨ$n������",
			120, -10, 25, 0,},
		{ "$N��ǰԾ��һ�������ֽ���������$wʹ��һʽ�������ơ�ֱ��$n��$l",
		140, -10, 30, 10,},
		{ "$N�β�ͦ����һʽ����ɽ�ơ�������$w�����ޱȣ������ӽ�ײ��$n��$l",
		170, 5, 35, 20,},
		{"$Nһʽ�������ơ���$w������һ���һ���󻡣�ƽƽ����$n��$l��ȥ",
		190, 5, 40, 30,},
		{ "$N����š���������鱧��Բ��һʽ�������ơ���$w�й�ֱ��������$n���ؿ�",
		240, 10, 50, 40,},
		{ "$Nһʽ�������ơ���$w������������������ֱ����Ю����֮����Ȼն��$n��$l",
		280, 5, 60, 49,},
		{ "$N����ʩ���������ơ���$w����Ƴ�һ����â��������ƿ�����$n��$l",
		350, 5, 75, 57,},
		{"$N˫�Ȱ�����ף�һʽ�������ơ������⻮������ԲȦ����������������",
		400, 5, 90, 64,},	
	};
	
	int level = me->query_skill("fumo_jian", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("��ʹ�õ��������ԡ�");

	if (me->query("hp") < 50)
		return notify_fail("���������������ħ����");

	me->receive_damage("hp", 35);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("�������������");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ�������̫ǳ��");

	return 1;
}

virtual int valid_enable(string usage) {return (usage == "sword") || (usage == "parry"); }
virtual int valid_combine(string combo) { return combo=="cibei-dao"; }

SKILL_END;