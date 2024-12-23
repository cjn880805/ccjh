//taishan_sword.h 泰山剑法

SKILL_BEGIN(CStaishan_sword);

virtual void create()
{
	set_name( "泰山剑法");	
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge,  damage;
	}action[5] = {
		{"$N右手$w斜指而下，左手五指正在屈指而数，从一数到五，握而成拳，又将拇指伸出，次而食指，终至五指全展，跟着又屈拇指而屈食指，再屈中指，然后手中$w剑光暴长，向$n的$l刺去",
			50, 170,},
		{ "$N手中$w一晃，向右滑出三步，一招“朗月无云”，转过身来，身子微矮，$w向$n斜斜刺去",
		-70, 120,},
		{ "$N手中$w圈转，一招「峻岭横空」去势奇疾，无数剑光刺向$n的$l",
		-40,  90,},
		{ "$N展开剑势，身随剑走，左边一拐，右边一弯，越转越急。猛地$w剑光暴长，一招「泰山十八盘」往$n$l刺去",
        -40, 140,},
		{ "$N手中$w倏地刺出，一连五剑，每一剑的剑招皆苍然有古意。招数古朴，内藏奇变，正是「五大夫剑」",
        60, 220,},};
		
  	int level = random(5);
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
        return notify_fail("你的内力不够，没有办法练泰山剑法。");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("你必须先找一把剑才能练剑法。");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
		|| me->query("mp") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习泰山剑法。");

    me->receive_damage("hp", 30);
    me->add("mp", -5);

	return 1;
}

SKILL_END;

