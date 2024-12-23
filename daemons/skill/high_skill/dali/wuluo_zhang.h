//wuluo_zhang.h  五罗轻烟掌

SKILL_BEGIN(CSwuluo_zhang);

virtual void create()
{
	set_name( "五罗轻烟掌");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("五罗轻烟掌必须与大理独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N屏息静气，手起一掌「轻烟袅袅」，轻轻柔柔地拍向$n",130 , 20, 0, 0,"瘀伤",},
		{"$N轻轻浅笑，绕到$n身后，左手做势温柔轻拥$n腰间。$n蹙眉急躲，$N右手一招「烟雾缭绕」，无声无息向$n的$l拍到", 150, 20, 30, 20,"内伤",},
		{"$N一招「烟海云涛」，双掌幻化出一片掌影，如一阵轻烟，将$n细细密密地笼罩于内", 150, 30,45 , 40,"瘀伤",},
		{"$N返身越出圈外，回首一招「云烟渺渺」，远远地向$n的$l轻轻拍出两掌，掌风刮到，陡然变盛直让$n呼不出气来", 200, 25, 55,60 ,"瘀伤",},
		{"$N左掌从右掌内围翻出，轻飘飘地向$n拍去，看到$n起手招架，右掌却自胸口疾速圈出，一招「烟雾弥漫」，赶超左掌，拍向$n的$l", 250, 70, 10, 80,"瘀伤",},
		{"$N双掌齐推，振起一阵劲风，一招「烟消云散」在一丈开外击向$n", 300, 20, 90,100 ,"瘀伤",},
	};
 	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("wuluo_zhang", 1))
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
		return notify_fail("练五罗轻烟掌必须空手。");
 
	if (me->query_skill("kurong_changong",1) < 20)
		return notify_fail("你的枯荣禅功太弱，无法练五罗轻烟掌。");
	
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练五罗轻烟掌。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练五罗轻烟掌。");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="jinyu_quan"; }

SKILL_END;

