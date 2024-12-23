// xingyi_zhang ������

SKILL_BEGIN(CSxingyi_zhang);

virtual void create()
{
	set_name( "������");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("�����Ʊ�������Ԫ�����ʹ�á�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$Nʹһ�С����α�Ӱ����˫�ֻ��˸���Ȧ������$n��$l",
		160, 5, 0, 0,"����",},
		{"$N�����鰴������ʹһ�С����ǵ�㡹����$n��$l��ȥ", 
		220, 10, 0, 30,"����",},
		{"$N˫����ȭ����ǰ��󻮻���һ�С������Ƕ�������$n��$l", 
		280, 15, 0, 60,"����",},
		{"$N�����黮������һ�ǡ��嶷�ǳ�������$n������", 
		360, 20, 0, 90,"����",},
		{"$Nʩ�����������ǡ������ֻ���$n��$l�����ֹ���$n���ɲ�", 
		410, 250, 0, 110,"����",},
	};
 	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("xingyi_zhng", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("�������Ʊ�����֡�");
 
	if (me->query_skill("shenyuan_gong",1) < 15)
		return notify_fail("�����Ԫ����򲻹����޷�ѧ�����ơ�");
	
	if (me->query("max_mp") < 50)
		return notify_fail("�������̫�����޷��������ơ�");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 30)
		return notify_fail("�������̫���ˡ�");
	
	if (me->query("mp") < 10)
		return notify_fail("������������������ơ�");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="canhe_zhi"; }

SKILL_END;

