SKILL_BEGIN(CSbanruo_zhang);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[10] = {
		{ "$Nǰ���߳������Ƚż��أ�һʽ����ճ�����������ֱ��������$n����������·",
			150, 5, 0,},
		{"$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ��Ѩ",
		160, 5, 12,},
		{"$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n��$l",
		170, 5, 18,},
		{"$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
		185, -5, 24,},
		{"$Nʹһʽ������ء���ȫ�������ת��˫��һǰһ���͵�����$n���ؿ�",
		200, 10, 30,},
		{"$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
		220, 5, 36,},
		{"$N���ϸ߸�Ծ��һʽ����ɽ��ˮ�����Ӹ����£���������$n��ȫ��",
		240, 20, 42,},
		{"$Nʹһʽ��ժ�ǻ�����������������˫�����֣�һ������$n��$l�ȥ",
		270, 10, 48,},
		{"$N�������»��أ�һʽ����������������Ȼ��Ϊ�������꣬����$n",
		310, 30, 54,},
		{"$Nһʽ����շ�ħ����˫�ֺ�ʮ������$n΢΢һҾ��ȫ���ھ�����˰���ӿ����",
		360, 10, 60,},
	};
	
	int level = me->query_skill("banruo_zhang", 1);
	for(int i = 10; i > 0; i--)
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
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");

	if (me->query("mp") < 20)
		return notify_fail("������������������ơ�");

	me->receive_damage("hp", 25);
	me->add("mp", -5);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������Ʊ�����֡�");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("��Ļ�Ԫһ������򲻹����޷�ѧ�����ơ�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷��������ơ�");

	return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" ||  usage=="parry";}
virtual int valid_combine(string combo) { return combo=="yizhi_chan"; }

SKILL_END;