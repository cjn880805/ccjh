SKILL_BEGIN(CSweituo_gun);

virtual void create()
{
	set_name( "韦陀棍");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("韦陀棍必须与少林独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"$N一招「黄石纳履」，手中$w如蜻蜓点水般，招招向$n的下盘要害点去",
			160, 5, 5, 10, 0,},
		{"$N把$w平提胸口，一拧身，一招「勒马停锋」，$w猛地撩向$n的颈部",
		180, 5, 10, 15, 8,},
		{"$N一招「平地龙飞」，全身滴溜溜地在地上打个大转，举棍向$n的胸腹间戳去",
		210, 5, 15, 20, 16,},
		{"$N伏地一个滚翻，一招「伏虎听风」，$w挟呼呼风声迅猛扫向$n的足胫",
		250, 15, 5, 25, 25,},
		{"$N一招「流星赶月」，身棍合一，棍端逼成一条直线，流星般向顶向$n的$l",
		300, 20, 15, 30, 35,},
		{"$N双手持棍划了个天地大圈，一招「红霞贯日」，一棍从圆心正中击出，撞向$n的胸口",
		350, 20, 15, 35, 44,},
		{"$N一招「投鞭断流」，$w高举，以雷霆万钧之势对准$n的天灵当头劈下",
		410, 25, 20, 40, 52,},
		{"$N潜运真力，一招「苍龙归海」，$w顿时长了数丈，矫龙般直射$n的胸口",
		470, 30, 25, 50, 60,},
	};

	int level = me->query_skill("weituo_gun", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
		
			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "club"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练韦陀棍。");
	me->receive_damage("hp", 25);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。");
	return 1;
}

virtual int valid_enable(string usage) {return  (usage == "club") || (usage == "parry"); }

SKILL_END;