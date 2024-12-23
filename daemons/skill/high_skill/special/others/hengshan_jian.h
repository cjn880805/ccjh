//hengshan_jian.h 恒山剑法

SKILL_BEGIN(CShengshan_jian);

virtual void create()
{
	set_name( "恒山剑法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge,  damage;
	}action[] = {
		{"$N提起$w，划了个半圈，斜斜向$n$l刺去",
			120, -40, 30,},
		{"$N突然间将$w交左手，反手刺出",
		140, -35, 35,},};
 
  	int level = 0;
	level = random(2);
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("damage", action[level].damage);
	
	return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "sword") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	 if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");

    if (DIFFERSTR(me->querystr("gender"), "女性") )
		return notify_fail("这种阴柔的剑法只有女子才适合学。");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

    if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

    if (me->query("hp") < 50)
		return notify_fail("你的体力不够练恒山剑法。");

    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

