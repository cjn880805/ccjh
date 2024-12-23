// yujiamu_quan.c ������ĸȭ
SKILL_BEGIN(CSyujiamu_quan);

virtual void create()
{
	set_name( "������ĸȭ");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("������ĸȭ������ѩɽ�ڹ����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$N����˫ȭ��ʹ��һ�С��ඥ������ͷ����$n��$l", 240, 5, 0,},
		{"$Nʹ��һ�С���ࡹ������һ�ͣ����ֻ���������һȭ����$n���ɲ�", 260, -5, 8,},
		{"$Nʹ��һ�С��ü������ȭ���$n��ǰ�أ�һ������ȭ��ɨ$n��̫��Ѩ", 280, 10, 16,},
		{"$N���ι��죬ʹһ�С�������˫ȭ���»���$n��$l", 350, 5, 24,},
		{"$Nʹ��һ�С����š���˫ȭ������������������ֱָ$n��$l", 380, -5, 32,},

		{"$N΢΢һЦ��ʹ��һʽ����������˫ȭǰ�������ֱȡ$n������", 350, 10, 40,},
		{"$Nʹ��һ�С����ġ���ȫ��ת��˫ȭ��ɨ$n��$l", 470, 20, 40,},
		{"$N����һԾ��ʹ��һ�С���ʤ����һȭ�ͻ�$n�ʺ�", 550, 5, 56,},
	};

	int level = me->query_skill("yujiamu_quan", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��������ĸȭ������֡�");
	if (me->query("hp") < 40)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�������������������ĸȭ��");
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
virtual int valid_combine(string combo) { return combo=="dashou_yin"; }
virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��������ĸȭ������֡�");
	else if (me->query("max_mp") < 50)
		return notify_fail("�������������");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if(me->query_skill("longxiang", 1) < 20)
		return notify_fail("���������������̫ǳ��");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("���С���๦���̫ǳ��");
	return 1;
}

SKILL_END;
