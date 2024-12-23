
// taixuan_gong.h ���͵�̫����
//code by Fisho
//date : 2000-12-08

//inherit SKILL;
//inherit FORCE;

SKILL_BEGIN(CStaixuan_gong);

virtual void create()
{
	set_name( "���͵�̫����");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$n�����ĳ������絽������$N��һ�ߡ�"},
		{"$n�ֱۻ�ת��ץס$N����һ�ƣ���$NԶԶ������"},
		{"$n������ţ���Ծ��������������ʮ�����⡣"},
		{"$Nֻ����ǰһ����ֻ����$n����һ�ϣ��Լ���������ȻĪ�����������ˡ�"},
	};
	
	return dodge_msg[random(4)];
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage;
		char damage_type[5];
	}action[] = {
		{"$N˫��һ�٣�һ�ɾ���������ӿ�������Ƶ�$n���Ժ���", 200, 20, 240, "����",},
		{"$N�����������$n�۰���Ѹ���ޱȵ�һ����$nһ�ӵ��˳�ȥ", 220, 20, 250, "����",},
		{"$N���һ�����ſ�һ��������$n������ȥ", 400, 30, 250, "����",},
		{"$N�����ϣ�˫���͵�����$n", 225, 30, 270, "����",},
		{"$N����΢�࣬ͻȻ����һ�ţ�����$n����·���ŵ���;���͵�һ̧������$n����", 230, 40, 300, "����",},
		{"$NͻȻ������һ�࣬��ס$n��·������������ӿ����", 230, 40, 300, "����",},
	};
	
	int level = 0;
	
	level = random(6);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return usage == "unarmed" || usage == "dodge" || usage == "parry" || usage == "force";
}

virtual int valid_learn(CChar * me)
{
	if (random(me->query("int")) > 11)		//ԭ����kar�� lanwood 2001-02-17
		return 1;
	return notify_fail("�����ʯ��ڤ˼������һ�ᣬ����Ŀ�����һ�㲻����");
	
}

SKILL_END;
