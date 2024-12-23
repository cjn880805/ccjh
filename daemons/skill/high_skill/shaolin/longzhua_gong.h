SKILL_BEGIN(CSlongzhua_gong);

virtual void create()
{
	set_name( "��צ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[12] = {
		{ "�ں��������У�$Nʹһ�С�����ʽ����˫���繳��ꫣ�����$n��$l",
			100, 5, 0, 0,},
		{"$N�͵���ǰԾ����һ�С�׽Ӱʽ���������߳���˫��ץ��$n������",
		110, 5, 5, 6,},
		{ "$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�����ʽ������$n��$l",
		120, 10, 5, 12,},
		{ "$N���������������ڻӣ�һ�С�����ʽ������$n�ؿ�",
		140, 10, 10, 18,},
		{ "$N�������գ�����������ɽ��һ�С�����ʽ�����͵ػ���$n��$l",
		160, 15, 10, 24,},
		{"$N�ڲ���ǰ�����ֻ��أ�����̽����һ�С�����ʽ������$n���ɲ�",
		190, 15, 15, 30,},
		{ "$N˫��ƽ����ǰ�����ֻ�ס���ţ�һ�С�����ʽ����������$n��$l",
		220, 20, 15, 35,},
		{ "$N������ǰ������Ҹ�º��գ���ָ�繳��һ�С���ȱʽ������$n�Ķ���",
		260, 20, 20, 40,},
		{ "$N����б��$n����֮�䣬һ�С�����ʽ��������ȡĿ�����ַ���$n���ɲ�",
		300, 25, 20, 45,},
		{ "$Nһ����ָ$n�Ľ�����һ�С��ὣʽ����һ������ץ��$n���еĳ���",
		350, 25, 25, 50,},
		{ "$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����ʽ��ʹ$n��������",
		 400, 30, 25, 55,},
		{ "$Nǰ���ŵأ�һ�ֶ����צ��һ��ָ�أ�һ�С�׷��ʽ����������$n��ȫ��",
		 460, 40, 30, 60,},
	};

	int level = me->query_skill("longzhua_gong", 1);
	for(int i = 12; i > 0; i--)
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

	return notify_fail("��צ�����������ֶ����ڹ����ʹ�á�");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("���������������צ����");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("����צ��������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ��צ����");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�����צ����");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="qianye_shou"; }

SKILL_END;