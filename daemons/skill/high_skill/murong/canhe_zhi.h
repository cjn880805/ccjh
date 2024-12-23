// canhe_zhi.h 参合指
//code by sound
//date : 2001-06-14

SKILL_BEGIN(CScanhe_zhi);

virtual void create()
{
	set_name( "参合指");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("参合指必须与神元功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N劲风激荡，双指错落搭置，一招「目不识丁」凶狠地向$n的$l插去", 
		100, 5, 10, 0,"刺伤",},
		{"$N大吼一声，十指上下分飞，一招「画龙点睛」，双指直取$n的$l", 
		130, 8, 15, 20,"刺伤",},
		{"$N十指互错，虚幻虚实，一招「扑朔迷离」，前后左右，瞬息间向$n攻出了六招", 
		170, 5, 20, 40,"刺伤",},
		{"$N身行腾空而起，一招「受宠若惊」，来势奇快，向$n的$l猛插下去", 
		200, 0, 25, 60,"刺伤",},
		{"$N身行一闪，若有若无捱到$n身前，一招「滔滔不绝」，插向$n的$l", 
		220, 15, 30, 70,"刺伤",},
		{"$N一招「退避三舍」，右手一拳击出，左掌化指，一掌一指凌空击向$n的$l", 
		300, 20, 0, 80,"内伤",},
		{"$N双掌化指，指中带掌，双手齐推，一招「卧薪尝胆」，一股排山倒海的内力，直扑$n$l", 
		360, -5, 0, 90,"内伤",},
		{"$N突然身行急转，一招「相煎何急」，十指飞舞，霎时之间将$n四面八方都裹住了", 
		420, -15, 0, 100,"震伤",},
	};

	int level = me->query_skill("canhe_zhi", 1);
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
        	return notify_fail("练参合指必须空手。");

	if ( me->query_skill("shenyuan_gong", 1) < 15)
        	return notify_fail("你的神元功火候不够，无法学参合指。");

	if ( me->query("max_mp") < 100)
        	return notify_fail("你的内力太弱，无法练参合指。");

	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
        	return notify_fail("你的体力不够，休息一下再练吧。");

	if ( me->query("mp") < 10)
        	return notify_fail("你的内力不够练参合指。");

	me->receive_damage("hp", 30);
	me->add("mp", -10);

	return 1;
	
}

int valid_combine(string combo) { return combo=="xingyi_zhang"; }

SKILL_END;
