//高级技能
//wudu_zhang 五毒掌

SKILL_BEGIN(CSwudu_zhang);

virtual void create()
{
	set_name( "五毒掌");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N双手一翻，两掌带着淡淡的蓝光，直向$n拍去", 180, 5, 20, 50, 0,},
		{"$N左掌虚晃，右掌直出，犹如毒蛇一般直迫$n的胸前", 220, 10, 15, 60, 10,},
		{"$N双掌翻飞，四周迷茫着一股暗淡的雾气，排向$n的全身", 260, 15, 20, 70, 20,},
		{"$N两掌一分，左掌如蝎，右掌似蛇，同时向$n击过去", 300, 20, 30, 80, 30,},
		{"$N默运内力，双掌忽然变黑，带着一股阴风只扑$n的全身", 340, 25, 20, 100, 40,},
	};

	int level = me->query_skill("wudu_zhang", 1);

	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("parry", action[level].parry);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练五毒掌。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练五毒掌必须空手。");
	if (me->query_skill("wudu_xinfa", 1) < 20)
		return notify_fail("你的五毒心法火候不够，无法学五毒掌。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练五毒掌。");
	return 1;
}

virtual int valid_enable(string usage) { return usage == "strike" || usage == "parry"; }

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("wudu_zhang")) > 10 )
		victim->apply_condition("wudu_poison",
								random(me->query_skill("wudu_zhang")/10 + 1) + 1 + 
								victim->query("condition/wudu_poison"));
	return 0;
}

SKILL_END;

//wudu-xinfa 五毒心法缺
//wudu_poison 五毒中毒

