//hengshan_sword.h 衡山剑法

SKILL_BEGIN(CShengshan_sword);

virtual void create()
{
	set_name( "衡山剑法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  dodge,  damage;
	}action[8] = {
		{ "$N右手$w慢慢指出，突然间在空中一颤，发出嗡嗡之声，跟着便是嗡嗡两剑，手中$w剑光暴长，向$n的$l刺去",
			-50,  170,},
		{"$N手中$w如鬼如魅，竟然已绕到了$n背后，$n急忙转身，耳边只听得嗡嗡两声",
		-70,  120,},
		{ "$N手中$w寒光陡闪，手中的$w，猛地反刺，直指$n胸口。这一下出招快极，抑且如梦如幻，正是“百变千幻衡山云雾十三式”中的绝招",
        -40,   90,},
		{ "$N不理会对方攻势来路，手中$w刷的一剑「泉鸣芙蓉」，向$n小腹刺去",
        -40,  100,},
		{ "$N不理会对方攻势来路，手中$w刷的一剑「鹤翔紫盖」，向$n额头刺去",
        -40,  100,},
		{ "$N手中$w倏地刺出，剑势穿插迂回，如梦如幻，正是一招「石廪书声」，向$n$l刺去",
        -60,  170,},
		{ "$N手中$w倏地刺出，极尽诡奇之能事，动向无定，不可捉摸。正是一招「天柱云气」，指向$n$l",
        -60, 180,},
		{ "$N飞身跃起，『雁回祝融』！，$w发出一声龙吟从半空中洒向$n的$l",
        -60, 160,},};
 
  	int level = random(8);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	 CContainer * ob;

    if( me->query("max_mp") < 50 )
        return notify_fail("你的内力不够，没有办法练衡山剑法。\n");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("你必须先找一把剑才能练剑法。");

    return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
    ||      me->query("mp") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习衡山剑法。");

    me->receive_damage("hp", 30);
    me->add("mp", -5);

    tell_object(me, "你按著所学练了一遍衡山剑法。", "practice");
    return 1;
}

SKILL_END;

