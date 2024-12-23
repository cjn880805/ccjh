SKILL_BEGIN(CSfengyun_shou);

virtual void create()
{
	set_name( "风云手");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N一式「风满长空」，以掌化爪，五指如钩，直逼$n的膻中要穴",
			120, 5, 15, 0,},
        {"$N左手虚晃，一式「烈火腾云」，右手上下直击，反扣$n的肩井大穴",
			130, 10, 20, 8,},
		{"$N使一式「草深雾泽」，掌指齐出，拍拿并施，拿向$n的三路要害",
			150,15, 20, 16,},
		{ "$N左手鹰抓，右手蛇举，一式「天目昭辉」疾扣$n的中节大脉",
		180, 20, 30, 24,},
        { "$N使一式「雷震四方」，四面八方出现无数掌影，一爪突出，抓向$n的胸口",
		220, 25, 35, 40,},
        { "$N两手环扣，全身关节啪啪作响，一式「水到渠成」，击向$n的$l",
		270, 30, 40, 48,},
        { "$N一式「山高林密」，十指齐伸，遮天蔽日般地笼罩$n的全身要穴",
		330, 35, 48, 54,},
        { "$N岳立霆峙，一式「地老天荒」，在一阵暴雷声中，双手同时拍中$n的七道死穴",
		400, 56, 60, 0,},
	};
	
	int level = me->query_skill("fengyun_shou", 1);
	for(int i = 8; i > 0; i--)
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

	return notify_fail("风云手必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练风云手。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练风云手必须空手。");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学风云手。");

	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练风云手。");

	return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="yingzhua_gong"; }

SKILL_END;