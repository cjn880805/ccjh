
// yunv_shenfa.h ��Ů��
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_shenfa);

void create()
{
	set_name( "��Ů��");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[80];
		int dodge;
	}action[5] = {
        {"����$n����һת��ʹ������Ѭ΢�ȡ�����ز������ܿ�����һ�С�", 0},
		{"$nһ�С���ʩ�ɴ����������ת��ٿ����һ��Ų�������ߡ�", 0},
		{"$n����Ʈ����հ֮��ǰ�������ں�ȴ�ǡ�������̨��������", 0},
		{"$nʹ��������岨����������ˮ�滬��һ�㣬���λ��˿�ȥ��", 5},
		{"����$n����ӰƮƮ���죬��˿������������һʽ����ɽ���ء�������", 5},
	};
	
	int level = random(5);
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
	if( me->query("hp") < 35 )
		return notify_fail("�������̫���ˣ���������Ů����");
	me->receive_damage("hp", 25);
	return 1;
}

SKILL_END;
