
// kongming_quan.h 空明拳
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSkongming_quan);

virtual void create()
{
	set_name( "空明拳");
	set("valid_force", "xiantian_qigong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  dodge,parry,force;
		char damage_type[5];
	}action[] = {
		{"$N使一招「空屋住人」，双手轻飘飘地箍向$n$l", 30, 20, 80,"瘀伤",},
		{"$N左掌一平,右掌一伸,一招「空碗盛饭」直拍$n的$l", -20, 20, 120,"瘀伤",},
		{"$N身形绕$n一转，双手上撩,一招「空钵装水」击向$n$l",25 , 20, 160,"瘀伤",},
		{"$N左掌一按,右掌一挥,一招「虚怀若谷」拍向$n的$l", -20, 0,200 ,"瘀伤",},
		{"$N使一招「空山鸟语」，$n的$l已围在$N的重重掌影之下", -20, 10, 240,"瘀伤",},
		{"$N神色一敛，使出「我心空明」，围绕$n的$l接连出掌",40 , 10, 300,"瘀伤",},
	};
 		
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(( i - 1 ) * 10 < me->query_skill("kongming_quan", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
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
        return notify_fail("练空明拳必须空手。");
	if ( me->query("max_mp") < 100)
        return notify_fail("你的内力太弱，无法练空明拳。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 40)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 10)
        return notify_fail("你的内力不够了！休息一下再练吧。");
	me->receive_damage("hp", 30);
	me->add("mp", -5);
	return 1;
}

SKILL_END;
