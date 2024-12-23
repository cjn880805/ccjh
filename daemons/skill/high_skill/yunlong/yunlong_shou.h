// yunlong-shou.c -������
SKILL_BEGIN(CSyunlong_shou);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, damage ,lvl;
	}action[] = {
		{"$Nһʽ����ľ�Ա�����ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ", 200, 30, 15, 10,},
		{"�ں��������У�$Nʹһ�С�����׽Ӱ����˫���繳��ꫣ�����$n��$l", 250, 35, 20, 20,},
		{"$N˫ȭ���裬һʽ������ȥ���������ֻ��ۣ�£��Ȧ״���ͻ�$n�����", 250, 30, 25, 30,},
		{"$N˫��ƽ�죬ʮָ΢΢���¶�����һ�С�ʮָǬ��������$n��$l", 300, 35, 30, 40,},

		{"$N���ֻ��أ�Ҹ�º��գ�������ָ�繳��һ�С�������ȱ������$n�Ķ���", 260, 40, 30, 50,},
		{"$N����б��$n����֮�䣬һ�С��������项������ȡĿ�����ַ���$n���ɲ�", 300, 35, 40, 60,},
		{"$Nһ����ָ$n�Ľ�����һ�С��������С�������ץ��$n���еı���", 350, 35, 50, 70,},
		{"$N����ָ��$n��ǰ�������Ѩ������бָ̫��Ѩ��һ�С�����������ʹ$n��������", 400, 40, 60, 80,},

		{"$Nһ�ֶ����צ��һ��ָ�أ�һ�С����Ƽ��ա�,��������$n��ȫ��", 420, 50, 70, 90,},
		{"$Nһʽ���������¡���ȭ���������֣��������ޣ�����������$n�ĵ���", 460, 60, 100, 100,},
		{"$N���������ʹһʽ���������ɡ�������΢��,��������$n��$l", 490, 60, 100, 80,},
	};

	int level = me->query_skill("yunlong_shou", 1);
	for(int i=11; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("������������������֡�");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "hand"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������ֱ�����֡�");
	if (me->query_skill("yunlong_shengong", 1) < 50)
		return notify_fail("��������񹦻�򲻹����޷�ѧ�����֡�");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("��Ļ����ڹ���򲻹����޷�ѧ�����֡�");
	if (me->query("max_mp") < 250)
		return notify_fail("�������̫�����޷��������֡�");
	if (me->query_skill("hand",1) <40)
		return notify_fail("��Ļ����ַ���򲻹����޷�ѧ�����֡�");
	if ( (2*me->query_skill("yunlong_xinfa",1)) <me->query_skill("yunlong_zhua",1))
		return notify_fail("��������ķ���򲻹����޷�����ѧ�����֡�");
	return 1;
}

virtual int valid_combine(string combo) { return combo=="yunlong_zhua"; }

SKILL_END;

/*
int valid_combine(string combo) { return combo=="yunlong-zhua"; }
*/