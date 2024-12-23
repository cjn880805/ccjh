
// qingfu_shenfa.h ������
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSqingfu_shenfa);

void create()
{
	set_name( "������");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[80];
		int dodge;
	}action[4] = {
		{"ֻ��$nһ�С�����Ǭ���������ζ�Ȼ���𣬶����$N��һ�С�", 0},
		{"$nһʽ���������١������λζ�����һ��Ʈ�����ܿ���$N��һ�С���", 0},
		{"$nʹ�������츣�ء���һ�����Ľ��󷭳����ܿ���$N���������ơ�", 5},
		{"$nһ�С��������𡹣�������ת��$Nֻ����ǰһ����$n������$N�����", 10},
	};

	int level = random(4);
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);

	return & m_actions;	
}

int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move");
}

int valid_learn(CChar * me)
{
	return 1;
}

int practice_skill(CChar * me)
{
	if(  me->query("hp") < 40 )
		return notify_fail("�������̫���ˣ���������������");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
