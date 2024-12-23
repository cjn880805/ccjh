SKILL_BEGIN(CSqianye_shou);

virtual void create()
{
	set_name( "����ǧҶ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[9] = {
		{"$Nһʽ���Ϻ���𡹣�������Σ���������ͻȻ����$n�ı����Ѩ",
			100, 10, 0, 0,},
		{ "$N����һ�Σ�һʽ����������������������$n�ļ�ͷ����ȭ����$n���ؿ�",
		110, 10, 0, 10,},
		{"$Nһʽ�����������������ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",
		130, 20, 5, 20,},
		{ "$N�������У�����ֱ����һʽ�������Ӱ������Ʈ��������$n������",
		160, 20, 10, 30,},
		{ "$Nʹһʽ��ˮ��׽�¡�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�",
		200, 30, 15, 38,},
		{ "$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n�����",
		250, 30, 20, 45,},
		{ "$Nһʽ��ˮ�ݳ�û����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ",
		310, 40, 25, 51,},
		{ "$N˫�ֱ�ȭ��һʽ����������������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��",
		380, 40, 30, 56,},
		{ "$Nһʽ������տա���ȭ���������֣��������ޣ�����������$n�ĵ���",
		460, 40, 40, 60,},
	};

	int level = me->query_skill("qianye_shou", 1);
	for(int i = 9; i > 0; i--)
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

	return notify_fail("����ǧҶ�ֱ��������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ((int)me->query("mp") < 20)
		return notify_fail("�����������������ǧҶ�֡�");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("������ǧҶ�ֱ�����֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ����ǧҶ�֡�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�������ǧҶ�֡�");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="longzhua_gong"; }

SKILL_END;