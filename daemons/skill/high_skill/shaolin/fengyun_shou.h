SKILL_BEGIN(CSfengyun_shou);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$Nһʽ���������ա������ƻ�צ����ָ�繳��ֱ��$n������ҪѨ",
			120, 5, 15, 0,},
        {"$N������Σ�һʽ���һ����ơ�����������ֱ��������$n�ļ羮��Ѩ",
			130, 10, 20, 8,},
		{"$Nʹһʽ���������󡹣���ָ��������ò�ʩ������$n����·Ҫ��",
			150,15, 20, 16,},
		{ "$N����ӥץ�������߾٣�һʽ����Ŀ�ѻԡ�����$n���нڴ���",
		180, 20, 30, 24,},
        { "$Nʹһʽ�������ķ���������˷�����������Ӱ��һצͻ����ץ��$n���ؿ�",
		220, 25, 35, 40,},
        { "$N���ֻ��ۣ�ȫ��ؽ�žž���죬һʽ��ˮ�����ɡ�������$n��$l",
		270, 30, 40, 48,},
        { "$Nһʽ��ɽ�����ܡ���ʮָ���죬������հ������$n��ȫ��ҪѨ",
		330, 35, 48, 54,},
        { "$N�������ţ�һʽ��������ġ�����һ�������У�˫��ͬʱ����$n���ߵ���Ѩ",
		400, 56, 60, 0,},
	};
	
	int level = me->query_skill("fengyun_shou", 1);
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

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("�����ֱ��������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("������������������֡�");
	me->receive_damage("hp", 25);
	me->add("mp", -5);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������ֱ�����֡�");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����֡�");

	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷��������֡�");

	return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="yingzhua_gong"; }

SKILL_END;