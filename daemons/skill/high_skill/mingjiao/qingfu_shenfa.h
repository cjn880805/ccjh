
// qingfu_shenfa.h 青蝠身法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSqingfu_shenfa);

void create()
{
	set_name( "青蝠身法");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[80];
		int dodge;
	}action[4] = {
		{"只见$n一招「福满乾坤」，身形陡然纵起，躲过了$N这一招。", 0},
		{"$n一式「五蝠献寿」，身形晃动，向一旁飘出，避开了$N这一招。。", 0},
		{"$n使出「洞天福地」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。", 5},
		{"$n一招「云龙百蝠」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。", 10},
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
		return notify_fail("你的体力太差了，不能练青蝠身法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
