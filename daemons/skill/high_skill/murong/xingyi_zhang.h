// xingyi_zhang 星移掌

SKILL_BEGIN(CSxingyi_zhang);

virtual void create()
{
	set_name( "星移掌");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "shenyuan_gong") || EQUALSTR(arg, "shenyuan_gong"))
		return 1;

	return notify_fail("星移掌必须与神元功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N使一招「幻形变影」，双手划了个半圈，按向$n的$l",
		160, 5, 0, 0,"瘀伤",},
		{"$N左手虚按，右手使一招「星星点点」，向$n的$l推去", 
		220, 10, 0, 30,"内伤",},
		{"$N双手握拳，向前向后划弧，一招「漫天星斗」打向$n的$l", 
		280, 15, 0, 60,"瘀伤",},
		{"$N左手虚划，右手一记「五斗星辰」击向$n的腰部", 
		360, 20, 0, 90,"瘀伤",},
		{"$N施出「北斗七星」，右手击向$n的$l，左手攻向$n的裆部", 
		410, 250, 0, 110,"瘀伤",},
	};
 	for(int i=5; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("xingyi_zhng", 1))
		{
			int level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
	
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练星移掌必须空手。");
 
	if (me->query_skill("shenyuan_gong",1) < 15)
		return notify_fail("你的神元功火候不够，无法学星移掌。");
	
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法练星移掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 10)
		return notify_fail("你的内力不够练星移掌。");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="canhe_zhi"; }

SKILL_END;

