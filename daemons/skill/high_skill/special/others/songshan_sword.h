//songshan_sword.h 嵩山剑法

SKILL_BEGIN(CSsongshan_sword);

virtual void create()
{
	set_name( "嵩山剑法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int dodge,  damage;
	}action[7] = {
		{"$N右手$w一立，举剑过顶，弯腰躬身，使一招‘万岳朝宗’正是嫡系正宗的嵩山剑法",
			50, 170,},
        { "$N手中$w突然间剑光一吐，化作一道白虹，端严雄伟，端丽飘逸，正是嵩山剑法的精要所在，一招‘千古人龙’向$n$l直刺过来",
        -70,  120,},
		{ "$N手中$w突然间剑光一吐，一招‘叠翠浮青’化成一道青光，气壮雄浑，向$n$l直刺过来",
        -70,  120,},
		{ "$N手中$w剑光一吐，一招‘玉进天池’威仪整肃，端严雄伟，向$n$l直刺过来",
        -70,  120,},
		{ "$N左手向外一分，右手$w向右掠出，使的是嵩山派剑法‘开门见山’",
        -70, 120,},
		{ "$N手中$w自上而下的向$n直劈下去，一招‘独劈华山’，真有石破天惊的气势，将嵩山剑法之所长发挥得淋漓尽致",
		-40,  90,},
		{ "$N手中$w刷的一剑自左而右急削过去，正是一招嵩山派正宗剑法‘天外玉龙’。但见$w自半空中横过，剑身似曲似直，长剑便如一件活物一般",
		-40, 140,},};
 
  	int level = random(7);
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
        return notify_fail("你的内力不够，没有办法练嵩山剑法。\n");

    if( !(ob = me->query_weapon())
		|| DIFFERSTR(ob->querystr("skill_type"), "sword") )
        return notify_fail("你必须先找一把剑才能练剑法。");

    return 1;
}


virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 30
		||   me->query("mp") < 5 )
        return notify_fail("你的内力或气不够，没有办法练习嵩山剑法。");
    me->receive_damage("hp", 30);
    me->add("mp", -5);
    
    return 1;
}

SKILL_END;

