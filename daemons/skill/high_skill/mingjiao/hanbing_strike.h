
// hanbing_strike.h 烈焰寒冰掌
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CShanbing_strike);

virtual void create()
{
	set_name( "烈焰寒冰掌");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,force;
		char damage_type[5];
	}action[] = {
		{"$N双掌一错，一招「风起云涌」，狂风般扫向$n的$l", 30, 200,"瘀伤",},
		{"$N一招「风雪满天」，身形突然旋转起来扑向$n，双掌拍向$n的$l", 40, 240,"瘀伤",},
		{"$N将寒毒运至左手，一招「万里雪飘」，迅疾无比地抓向$n的$l", 50, 280,"瘀伤",},
		{"$N后退一步，突然一招「千里冰封」，掌挟奇寒之气拍向$n的$l", 60, 300,"瘀伤",},
	};
 		
	int level = 0;
	
	for(int i=4; i>0; i--)
	{
		if(( i - 1) * 10 < me->query_skill("hanbing_strike", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("force", action[level].force);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "unarmed") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_weapon()  )
   return notify_fail("练烈焰寒冰掌必须空手。");
	if ( me->query_skill("shenghuo_shengong", 1) < 40)
   return notify_fail("你的圣火神功火候不够，无法练烈焰寒冰掌。");
    if ( me->query("max_mp") < 300)
   return notify_fail("你的内力太弱，无法练寒冰掌");
    return 1;

}

virtual int practice_skill(CChar * me)
{
    if ( me->query("hp") < 30)
   return notify_fail("你的体力太低了，先休息一下吧。");
    if ( me->query("mp") < 8)
   return notify_fail("你的内力不够练寒冰掌。");
    if (me->query_skill("hanbing_strike", 1) < 50)
   me->receive_damage("hp", 20);
    else
   me->receive_damage("hp", 30);
    me->add("mp", -5);
    return 1;

}

 
SKILL_END;
