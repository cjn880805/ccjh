// jinyu_quan.c 金玉拳

SKILL_BEGIN(CSjinyu_quan);

virtual void create()
{
	set_name( "金玉拳");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("金玉拳必须与大理独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force,dodge, damage, lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「金光灿烂」，双拳一上一下, 向$n挥去",120 ,10 , 20,0 ,"瘀伤",},
		{"$N一招「其利断金」，幻出一片拳影，气势如虹，击向$n的头部", 140, 20, 30, 20,"瘀伤",},
		{"$N身影向上飘起，脸浮微笑，一招「蓝田美玉」，轻轻拍向$n的$l", 150, 20, 45,40 ,"瘀伤",},
		{"$N一招「金玉其外」，双拳一合，$n只觉到处是$N的拳影", 160, 25, 60, 60,"瘀伤",},
		{"$N绕着$n一转，满场游走，拳出如风，不绝击向$n，正是一招「金玉满堂」", 170, 30, 60, 80,"瘀伤",},
		{"只见$N一个侧身退步，左手虚晃，突然猛跨两步，已到$n面前，右拳陡出，事先绝无征兆，迅如崩雷，一招「点石成金」击向$n的前胸",180 ,35 , 80, 100,"瘀伤",},
		{"$N一招「众口铄金」，扑向$n，似乎$n的全身都被拳影笼罩", 280, 30, 100,120 ,"瘀伤",},
	};
 
	int level = 0;

	for(int i=7; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("jinyu_quan", 1))
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
	return (usage == "cuff")  || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
    if (me->query_skill("kurong_changong",1) < 20)
		return notify_fail("你的枯荣禅功火候不够，无法练金玉拳。");

	if (me->query_weapon() )
		return notify_fail("练金玉拳必须空手。");

	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练金玉拳。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 50)
		return notify_fail("你的体力太低了。");

	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练金玉拳。");

	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_combine(string combo) { return combo=="wuluo_zhang"; }

SKILL_END;
