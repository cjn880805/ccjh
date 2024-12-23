// tianshan_zhang.h ��ɽ�ȷ�
SKILL_BEGIN(CStianshan_zhang);

virtual void create()
{
	set_name( "��ɽ�ȷ�");
	set("valid_force", "huagong_dafa");
}

virtual int valid_enable(string usage) { return (usage == "staff") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 80)
		return notify_fail("�������������");

	return 1;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[10] = {
		{"$Nʹ��һ�С����ӿ�����������$w�󿪴���ɨ��$n��$l",
			180, -3, 40, 20,},
		{"$N����$w������죬һ�С�ɽ����������$n��$l��ȥ",
			240, -5, 70, 23,},
		{"$N����$w���Ӹ�����ʹһ�С���ɽѩ��������$n��$l",
			260, -10, 100, 30,},
		{"$Nһ�С�������ѩ��������Ʈ�����ߣ�����$w����$n��$l",
			240, -30, 120, 45,},
		{"$Nʹһ�С��ع�õ硹������$w��һ���������$n��$l",
			270, -20, 130, 60,},
		{"$Nʹ���ġ���˪��Ӱ����$w������Ӱ��������$n��$l",
			300, -20, 130, 75,},
		{"$N��$wƾ��һָ��һ�С���ʯ���̡�����$n��$l",
			320, -20, 140, 90,},
		{"$N����һԾ������$wһ�С�������������׼$n��$lɨȥ",
			340, -40, 150, 105,},
		{"$N����$w�й�ֱ����һʽ�����ȳ��硹��׼$n��$l��ȥ",
			350, -40, 160, 120,},
		{"$Nһ�С����·ת����$w�����ػ���$n��$l��ȥ",
		480, -5, 180, 145,},};
		
	int level = me->query_skill("tianshan_zhang",1);

	for(int i = 10; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
	
			break;		
		}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("���õ��������������õ�������ȣ�");
	
	if (me->query("hp") < 50)
		return notify_fail("��Ȼ����о��ĵ�����ɽ�ȷ�������������������ˡ�");
	
	me->receive_damage("hp", 25);

	return 1;
}
virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 250) 
	{
		victim->apply_condition("xx_poison", random(160) + 1 +
			victim->query("condition/xx_poison"));
    }
	return "";
}
SKILL_END;