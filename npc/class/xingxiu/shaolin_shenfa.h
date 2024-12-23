SKILL_BEGIN(CSshaolin_shenfa);

void create()
{
	set_name("������");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int dodge;
	}action[8] = {
		{"$nһʽ��һέ�ɽ�����ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ", 0,},
		{"$nһʽ�������Ӳ�����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�", 0,},
		{"$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����", 0,},
		{"$nһʽ����۵糸����˫�ŵ�أ�ȫ��һ�����磬��������$N�ɱ���", 0,},
		{"$nһʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���", 5,},
		{"$nһʽ������˫�ɡ��������������������ݷ����У���$Nͷ����Ծ������", 5,},
		{"$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��", 10,},
		{"$nһʽ���ɷ�鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�", 15},
	};

	int level = me->query_skill("shaolin_shenfa", 1);

	int zhaoshu = 8;
	if (level < 80 )
		zhaoshu--;

	if (level < 60)
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;
       
	if (random(me->query_skill("dodge")) > 100 &&
            me->query_skill("force") > 90 &&
            me->query("mp") > 500) 
	{
        me->add("mp",-5);

		m_actions.set("action","$YEL$n��Ȼʹ������������֮����������Ӱ�����������������ʧ����Ӱ����!$COM");
        m_actions.set("dodge", 300);
		return &m_actions;
	}

	level = random(zhaoshu);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);

	return & m_actions;
}

int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

int valid_learn(CChar * me)
{
	return 1;
}

int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������������");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;