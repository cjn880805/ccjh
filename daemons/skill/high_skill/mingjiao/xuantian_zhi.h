
// xuantian_zhi.h 玄天无情指
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSxuantian_zhi);

virtual void create()
{
	set_name( "玄天无情指");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "wuzheng_xinfa") || EQUALSTR(arg, "xuantian_shengong"))
		return 1;

	return notify_fail("玄天无情指必须与玄天神功或无争心法配合使用。");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl,damage;
		char damage_type[5];
	}action[] = {
		{"$N左指挥出，一式「黯然消魂」，削向$n的掌缘", 100, 5, 0,100 ,"刺伤",},
		{"$N全身之力聚于一指，一式「天似无情」，指向$n的胸前",150 , 5, 15, 125,"刺伤",},
		{"$N左掌贴于神道穴，右手一式「情根深种」，向$n的$l划过", 200, 8, 25, 145,"刺伤",},
		{"$N双目怒视，一式「情在天涯」，双指拂向$n的额、颈、肩、臂、胸、背", 280,5 , 65,165 ,"刺伤",},
		{"$N一式「独饮情伤」，左掌掌心向外，右指蓄势点向$n的$l", 350, 15, 80,180 ,"刺伤",},
		{"$N右手伸出，十指叉开，一式「无诉别情」，小指拂向$n的太渊穴", 430, 20, 100, 190,"刺伤",},
		{"$N双迸出无数道劲气，一式「情意绵绵」射向$n的全身", 550, 25,120 , 300,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("xuantian_zhi", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
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
		return notify_fail("练玄天无情指必须空手。");
	if ( me->query_skill("finger", 1) < 30)
		return notify_fail("你的基本指法根基不扎实，无法练玄天无情指。");
	if ( me->query("max_mp") < 500)
		return notify_fail("你的内力太弱，无法练玄天无情指。");
	if ( me->query_skill("xuantian_shengong", 1) < 70)
		return notify_fail("你的玄天神功火候不足，无法练玄天无情指。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的精太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练玄天无情指。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;




