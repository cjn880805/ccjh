// yujiamu_quan.c 金刚瑜迦母拳
SKILL_BEGIN(CSyujiamu_quan);

virtual void create()
{
	set_name( "金刚瑜迦母拳");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "xiaowuxiang") || EQUALSTR(arg, "longxiang"))
		return 1;

	return notify_fail("金刚瑜迦母拳必须与雪山内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[] = {
		{"$N并举双拳，使出一招「灌顶」，当头砸向$n的$l", 240, 5, 0,},
		{"$N使出一招「解苦」，身形一低，左手护顶，右手一拳击向$n的裆部", 260, -5, 8,},
		{"$N使出一招「颦眉」，左拳虚击$n的前胸，一错身，右拳横扫$n的太阳穴", 280, 10, 16,},
		{"$N神形怪异，使一招「嗔恚」，双拳上下击向$n的$l", 350, 5, 24,},
		{"$N使出一招「静寂」，双拳交错，缓缓击出，劲气直指$n的$l", 380, -5, 32,},

		{"$N微微一笑，使出一式「妙音」，双拳前后击出，直取$n的左胸", 350, 10, 40,},
		{"$N使出一招「明心」，全身疾转，双拳横扫$n的$l", 470, 20, 40,},
		{"$N飞身一跃，使出一招「制胜」，一拳猛击$n咽喉", 550, 5, 56,},
	};

	int level = me->query_skill("yujiamu_quan", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练金刚瑜迦母拳必须空手。");
	if (me->query("hp") < 40)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练金刚瑜迦母拳。");
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "parry"; }
virtual int valid_combine(string combo) { return combo=="dashou_yin"; }
virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练金刚瑜迦母拳必须空手。");
	else if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if(me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。");
	return 1;
}

SKILL_END;
