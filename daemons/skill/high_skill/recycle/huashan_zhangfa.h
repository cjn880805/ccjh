// huashan_zhangfa.h 华山掌法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_zhangfa);

virtual void create()
{
	set("name", "华山掌法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force,dodge,parry,damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一式「白云出岫」，双掌间升起一团淡淡的白雾，缓缓推向$n的$l", 180, 5, 20, 10,0 ,"瘀伤",},
		{"$N并指如剑，一式「白虹贯日」，疾向$n的$l戳去",220 , 10, 15, 20, 10,"瘀伤",},
		{"$N使一式「云断秦岭」，左掌微拂，右掌乍伸乍合，猛地插往$n的$l", 260,15 , 20,30 , 20,"瘀伤",},
		{"$N双掌隐隐泛出青气，一式「青松翠翠」，幻成漫天碧绿的松针，雨点般向$n击去", 300, 20, 30, 40, 30,"瘀伤",},
		{"$N身形往上一纵，使出一式「天绅倒悬」，双掌并拢，笔直地向$n的$l插去", 340, 25, 20, 50, 40,"瘀伤",},
		{"$N身形一变，使一式「无边落木」，双掌带着萧刹的劲气，猛地击往$n的$l", 380, 25, 25,60 , 50,"瘀伤",},
		{"$N使一式「高山流水」，左掌凝重，右掌轻盈，同时向$n的$l击去", 420, 30, 30, 70, 60,"瘀伤",},
		{"$N突地一招「金玉满堂」，双掌挟着一阵风雷之势，猛地劈往$n的$l", 460, 30, 35, 80, 70,"瘀伤",},
		{"$N一式「风伴流云」，双掌缦妙地一阵挥舞，不觉已击到$n的$l上",500 ,40 , 45,90 ,80 ,"瘀伤",},
		{"$N一式「烟雨飘渺」，身形凝立不动，双掌一高一低，看似简单，却令$n无法躲闪", 540, 45, 50, 110, 90,"瘀伤",},
	};
 	
	int level = 0;
	
	for(int i=10; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("huashan_zhangfa", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
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
	if (me->query_weapon())
		return notify_fail("练华山掌法必须空手。");
	if ( me->query_skill("zixia_shengong", 1) < 20)
		return notify_fail("你的紫霞神功火候不够，无法学华山掌法。");
	if ( me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练华山掌法。");
	return 1;

}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ( me->query("mp") < 40)
		return notify_fail("你的内力不够练华山掌法。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

//	return __DIR__"huashan-zhangfa/" + action;

SKILL_END;
