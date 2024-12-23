// tianshan_zhang.h 天山杖法
SKILL_BEGIN(CStianshan_zhang);

virtual void create()
{
	set_name( "天山杖法");
	set("valid_force", "huagong_dafa");
}

virtual int valid_enable(string usage) { return (usage == "staff") || (usage == "parry");}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 80)
		return notify_fail("你的内力不够。");

	return 1;
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	static struct {
		char action[255];
		int force, dodge, damage;
		int lvl;
	}action[10] = {
		{"$N使出一招「冰河开冻」，手中$w大开大阖扫向$n的$l",
			180, -3, 40, 20,},
		{"$N手中$w阵阵风响，一招「山风凛冽」向$n的$l攻去",
			240, -5, 70, 23,},
		{"$N举起$w，居高临下使一招「天山雪崩」砸向$n的$l",
			260, -10, 100, 30,},
		{"$N一招「残阳照雪」，纵身飘开数尺，手中$w砸向$n的$l",
			240, -30, 120, 45,},
		{"$N使一招「回光幻电」，手中$w幻一条疾光点向$n的$l",
			270, -20, 130, 60,},
		{"$N使出的「风霜碎影」，$w连挥杖影霍霍劈向$n的$l",
			300, -20, 130, 75,},
		{"$N的$w凭空一指，一招「断石狼烟」点向$n的$l",
			320, -20, 140, 90,},
		{"$N纵身一跃，手中$w一招「长空雷隐」对准$n的$l扫去",
			340, -40, 150, 105,},
		{"$N手中$w中宫直进，一式「冰谷初虹」对准$n的$l点去",
			350, -40, 160, 120,},
		{"$N一招「峰回路转」，$w左右迂回向$n的$l点去",
		480, -5, 180, 145,},};
		
	int level = me->query_skill("tianshan_zhang",1);

	for(int i = 10; i > 0; i--)
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
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你拿的武器是杖吗？你拿的真的是杖？");
	
	if (me->query("hp") < 50)
		return notify_fail("虽然你很有决心地练天山杖法，可是你的体力不够了。");
	
	me->receive_damage("hp", 25);

	return 1;
}
virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( random(me->query_skill("poison",1)) > 250) 
	{
		victim->apply_condition("xx_poison", random(160) + 1 +
			victim->query("condition/xx_poison"));
    }
	return "";
}
SKILL_END;