SKILL_BEGIN(CSxiangmo_chu);

virtual void create()
{
	set_name( "金刚降魔杵");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int dodge, parry, lvl, damage;
	}action[8] = {
		{ "$N高举手中$w，使出一招「金刚再世」，直劈$n的$l  ",
			-5, 10, 0, 30,},
		{"$N使出「金刚伏魔」，单手舞动$w，一伏身，$w横扫$n的下盘  ",
		5, 0, 8, 40,},
		{ "$N反身仰面，使出一式「金刚宣法」，双手握$W，一棍直刺$n的$l  ",
		10, 5, 16, 50,},
		{"$N使出一招「引趣众生」，双手举棍撩向$n的裆部  ",
		0, 10, 24, 60,},
		{ "$N舞动手中$w，使出「歌舞阎罗」，顿时罩住$n的全身  ",
        10, 10, 32, 80,},
		{"$N使出一招「浮游血海」，全身贴地而飞，一棍直捣$n的$l  ",
		15, 5, 40, 100,},
		{ "$N使出一式「驱鬼御魔」，以棍支地，双足飞揣$n的面门  ",
		20, 0, 48, 150,},
		{ "$N运力于掌，使出「荡魔除妖」，飞身疾进，手中$w横扫$n的$l  ",
        20, 15, 56, 180,},
	};

	int level = me->query_skill("xiangmo_chu", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
		
			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了金刚降魔杵。");
	me->receive_damage("hp", 30);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
	if (me->query_skill("longxiang", 1) >= 20 ||
	    me->query_skill("xiaowuxiang", 1) >= 20)
		return 1;
	else if (me->query_skill("longxiang", 1) < 20)
		return notify_fail("你的龙象般若功火候太浅。");
	else if (me->query_skill("xiaowuxiang", 1) < 20)
		return notify_fail("你的小无相功火候太浅。");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "staff" || usage == "parry";  }

SKILL_END;