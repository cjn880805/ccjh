SKILL_BEGIN(CSlongzhua_gong);

virtual void create()
{
	set_name( "龙爪功");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[12] = {
		{ "在呼呼风声中，$N使一招「捕风式」，双手如钩如戢，插向$n的$l",
			100, 5, 0, 0,},
		{"$N猛地向前跃出，一招「捉影式」，两腿踢出，双手抓向$n的面门",
		110, 5, 5, 6,},
		{ "$N双手平伸，十指微微上下抖动，一招「抚琴式」打向$n的$l",
		120, 10, 5, 12,},
		{ "$N左手上拦，右手内挥，一招「击鼓式」击向$n胸口",
		140, 10, 10, 18,},
		{ "$N右手虚握，左手掌立如山，一招「批亢式」，猛地击向$n的$l",
		160, 15, 10, 24,},
		{"$N腾步上前，左手护胸，右手探出，一招「掏虚式」击向$n的裆部",
		190, 15, 15, 30,},
		{ "$N双手平提胸前，左手护住面门，一招「抱残式」右手推向$n的$l",
		220, 20, 15, 35,},
		{ "$N两手胸前环抱，腋下含空，五指如钩，一招「守缺式」插向$n的顶门",
		260, 20, 20, 40,},
		{ "$N右腿斜插$n二腿之间，一招「抢珠式」，上手取目，下手反勾$n的裆部",
		300, 25, 20, 45,},
		{ "$N一手虚指$n的剑诀，一招「夺剑式」，一手劈空抓向$n手中的长剑",
		350, 25, 25, 50,},
		{ "$N左手指向$n胸前的五道大穴，右手斜指太阳穴，一招「拿云式」使$n进退两难",
		 400, 30, 25, 55,},
		{ "$N前脚着地，一手顶天成爪，一手指地，一招「追日式」劲气笼罩$n的全身",
		 460, 40, 30, 60,},
	};

	int level = me->query_skill("longzhua_gong", 1);
	for(int i = 12; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("龙爪功必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练龙爪功。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
		return notify_fail("练龙爪功必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学龙爪功。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练龙爪功。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="claw" ||  usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="qianye_shou"; }

SKILL_END;