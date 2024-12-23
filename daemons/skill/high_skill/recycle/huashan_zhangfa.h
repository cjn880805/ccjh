// huashan_zhangfa.h ��ɽ�Ʒ�
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_zhangfa);

virtual void create()
{
	set("name", "��ɽ�Ʒ�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$Nһʽ�����Ƴ�ᶡ���˫�Ƽ�����һ�ŵ����İ�����������$n��$l", 180, 5, 20, 10,0 ,"����",},
		{"$N��ָ�罣��һʽ���׺���ա�������$n��$l��ȥ",220 , 10, 15, 20, 10,"����",},
		{"$Nʹһʽ���ƶ����롹������΢��������է��է�ϣ��͵ز���$n��$l", 260,15 , 20,30 , 20,"����",},
		{"$N˫����������������һʽ�����ɴ�䡹���ó�������̵����룬������$n��ȥ", 300, 20, 30, 40, 30,"����",},
		{"$N��������һ�ݣ�ʹ��һʽ������������˫�Ʋ�£����ֱ����$n��$l��ȥ", 340, 25, 20, 50, 40,"����",},
		{"$N����һ�䣬ʹһʽ���ޱ���ľ����˫�ƴ�����ɲ�ľ������͵ػ���$n��$l", 380, 25, 25,60 , 50,"����",},
		{"$Nʹһʽ����ɽ��ˮ�����������أ�������ӯ��ͬʱ��$n��$l��ȥ", 420, 30, 30, 70, 60,"����",},
		{"$Nͻ��һ�С��������á���˫��Ю��һ�����֮�ƣ��͵�����$n��$l", 460, 30, 35, 80, 70,"����",},
		{"$Nһʽ��������ơ���˫�������һ����裬�����ѻ���$n��$l��",500 ,40 , 45,90 ,80 ,"����",},
		{"$Nһʽ������Ʈ�졹����������������˫��һ��һ�ͣ����Ƽ򵥣�ȴ��$n�޷�����", 540, 45, 50, 110, 90,"����",},
	};
 	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_zhangfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("����ɽ�Ʒ�������֡�");
	if ( me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("�����ϼ�񹦻�򲻹����޷�ѧ��ɽ�Ʒ���");
	if ( me->query("max_mp") < 100)
		return notify_fail("�������̫�����޷�����ɽ�Ʒ���");
	return 1;

}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	if ( me->query("mp") < 40)
		return notify_fail("���������������ɽ�Ʒ���");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//	return __DIR__"huashan-zhangfa/" + action;

SKILL_END;
