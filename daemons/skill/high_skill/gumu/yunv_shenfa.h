
// yunv_shenfa.h 玉女身法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyunv_shenfa);

void create()
{
	set_name( "玉女身法");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[80];
		int dodge;
	}action[5] = {
        {"但是$n身形一转，使出「麝熏微度」，蓦地不见，避开了这一招。", 0},
		{"$n一招「西施浣纱」，身随意转，倏地往一旁挪开了三尺。", 0},
		{"$n身形飘忽，瞻之在前，忽焉在后，却是「走马兰台」的身法。", 0},
		{"$n使出「洛河清波」，犹如在水面滑行一般，身形晃了开去。", 5},
		{"可是$n的身影飘飘渺渺，竟丝毫不着力，是一式「蓬山万重」的身法。", 5},
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
		return notify_fail("你的体力太差了，不能练玉女身法。");
	me->receive_damage("hp", 25);
	return 1;
}

SKILL_END;
