SKILL_BEGIN(CSyingzhua_gong);

virtual void create()
{
	set_name( "ӥצ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"$Nȫ��εض��𣬰����һ�����һʽ����ӥϮ�á���Ѹ�͵�ץ��$n��$l",
		100, 5, 5, 0, 0,},
		{"$N����ֱ����˫��ƽ�죬һʽ����ӥչ�᡹��˫צһǰһ��£��$n��$l",
		120, 10, 10, 5, 10,},
		{"$Nһʽ���γ��ɡ���ȫ����б��ƽ�ɣ�����һ����˫צ����$n�ļ�ͷ",
		150, 10, 10, 10, 20,},
		{"$N˫צ�����Ͼ٣�ʹһʽ��ӭ��������һ�����ֱ�Ϯ��$n����Ҹ����",
		190, 15, 15, 15, 30,},
		{"$Nȫ�������ǰ��һʽ��������צ������צͻ�������Ȱ�ץ��$n���ؿ�",
		250, 20, 20, 15, 40,},
		{"$N���ػ��У�һʽ������հ�ա�������Ϯ�����д�Ѩ�����ַ�ץ$n���ɲ�",
		310, 25, 25, 20, 50,},
		{"$N��������צ���棬һʽ���������ա��������������ƿն�����Ѹ���ޱȵػ���$n",
		380, 25, 25, 25, 55,},
		{"$N�ڿո߷����ɣ�һʽ��ӥ�����������ж�ʱ�Գ�һ������צӰ����������$n",
		470, 40, 40, 30, 60,},
	};

	int level = me->query_skill("yingzhua_gong", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
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
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("�������������ӥצ����");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("��ӥצ��������֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧӥצ����");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷���ӥצ����");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="claw" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="fengyun_shou";   }

SKILL_END;