SKILL_BEGIN(CSshaolin_shenfa);

void create()
{
	set_name( "������");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int dodge;
	}action[8] = {
		{"$nһʽ��һέ�ɽ�����ǰ��Žż�Ÿ��࿿��������������ˮ�㻬�����ࡣ", 5,},
		{"$nһʽ�������Ӳ�����˫��ǰ�죬ȫ������ƽ�ɣ���ʱ������$N���������ơ�", 10,},
		{"$nһʽ���Ʋ����Ρ����㲻�����ֲ�̧��һת�ۼ���Ƶ���$N�����", 5,},
		{"$nһʽ����۵糸����˫�ŵ�أ�ȫ��һ�����磬��������$N�ɱ���", 10,},
		{"$nһʽ���������ա���ȫ���ֱ���εض����ڰ����һת�����䵽����Զ�ĵط���", 10,},
		{"$nһʽ������˫�ɡ��������������������ݷ����У���$Nͷ����Ծ������", 10,},
		{"$nһʽ��������ˮ����˫�ŵ�أ�ȫ��Ϊһ����Ӱ����������$N���˼�ת��", 20,},
		{"$nһʽ���ɷ�鳲�������������ݰ㼱ת�������γ�һ�������У���$N������䣬�������á�", 30},
	};

	int level = me->query_skill("shaolin_shenfa", 1);

	int zhaoshu = 8;
	if (level < 80 )
		zhaoshu--;

	if (level < 60)
		zhaoshu--;

	if (level < 40 )
		zhaoshu--;
       
	int lvl = me->query_skill("hunyuan_yiqi",1);
	int lvl2 = me->query_skill("yijinjing",1);
	
	if (random( lvl > lvl2 ? lvl : lvl2 ) > 50 &&
		random(me->query_skill("dodge")) > 100 &&
		random(me->query_skill("force")) > 60 &&
		random(me->query("mp")) > 40) 
	{
        me->add("mp",-5);

		m_actions.set("action","$YEL$n��Ȼʹ������������֮����������Ӱ�����������������ʧ����Ӱ����!$COM");
		m_actions.set("dodge", 50);
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