//kao.h 靠
SKILL_BEGIN(CSkao);

virtual void create()
{
	set_name( "靠");
	
}

virtual int valid_enable(string usage) { return usage=="unarmed" ||  usage=="parry";}


virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
        return notify_fail("练靠必须空手。");
    if (me->query("max_mp") < 200)
        return notify_fail("你的内力太弱，无法练靠。");

	return 1;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[4] = {
		{"$N乘$n出招之际，一个震脚，使出绝招“铁山靠”撞向的$l",
			120, 10, 30, 0,},
		{"$N抓住对方右手，一招“缠丝靠”撞向$n的$l",
			150, 20, 45, 0,},
		{"$N身形围$n转了半圈，一招“里门顶靠”撞向$n的身体重心之处",
			180, 30, 55, 0,},
		{"$N身形一矮，猛然一招“上步冲靠”直撞向$n的空档",
		240, 50, 100, 100,},
	};

	int level = me->query_skill("kao",1);

	for(int i = 4; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("damage", action[level].damage);
			m_actions.set("dodge", action[level].dodge);
	
			break;		
		}

	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练靠。");
	
	me->receive_damage("hp", 30);
    me->add("mp", -20);

	return 1;
}

SKILL_END;