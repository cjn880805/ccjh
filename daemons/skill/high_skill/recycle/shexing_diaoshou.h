//shexing_diaoshou.h ���ε���

//coded by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSshexing_diaoshou);

virtual void create()
{
	set_name( "���ε���");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge, damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһʽ�����߳�������������Σ���������ͻȻ����$n�ı����Ѩ", 90, 10, 0, 0,"����",},
		{"$N����һ�Σ�һʽ����ͷ��β������������$n�ļ�ͷ����ȭ����$n���ؿ�", 120, 10,0, 10,"����",},
		{"$Nһʽ���������㡹�����ֻ�£��צ��һ���־����$n���ʺ�Ҫ��",130 , 20, 5, 20,"����",},
		{"$N�������У�����ֱ����һʽ��������Ӱ������Ʈ��������$n������", 160 , 20, 10, 30,"����",},
		{"$Nʹһʽ��������ܡ�����ȭ�ϸ�����̽��ͻ����ץ��$n���ɲ�", 200, 30, 15,38 ,"����",},
		{"$Nһʽ���������񡹣�ʮָ����������ʵʵ��Ϯ��$n��ȫ��ҪѨ", 310, 40, 25, 51 ,"����",},
		{"$N˫�ֱ�ȭ��һʽ��������ӿ������Ӱ���ɣ�ͬʱ��$nʩ���žŰ�ʮһ��", 380, 40, 30, 56,"����",},
		{"$Nһʽ���������š���ȭ���������֣��������ޣ�����������$n�ĵ���", 460, 40, 40, 60,"����",},
	};
 	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("shexing_diaoshou", 1))
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
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	
	if (me->query_weapon())
		return notify_fail("�����ε��ֱ�����֡�");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("��Ļ���������򲻹����޷�ѧ���ε��֡�");
	if (me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷������ε��֡�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if (me->query("mp") < 20)
		return notify_fail("����������������ε��֡�");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

SKILL_END;
