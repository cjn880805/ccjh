//kuangfeng_blade 狂风刀法
//by sound
//2001-07-21

SKILL_BEGIN(CSkuangfeng_blade);

virtual void create()
{
	set_name( "狂风刀法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  force, dodge,  parry, damage, lvl;
	}action[10] = {
		{"$N手中$w轻挥，一招「风平浪静」，看似平缓实则迅速地向$n的$l撩去",
			150, 10, 5, 10, 0,},
		{"$N一招「风起云涌」，右脚一点，$w寒光闪闪，快速涌$n的$l",
		170, 35, 10, 20, 10,},
		{"$N一招「风卷残云」，手臂一抡，刀锋一卷，自上而下斩向$n",
		190, 25, 5, 25, 20,},
		{"$N一招「风流云散」，侧身而退，$w却在胸前划出一道圆弧，横劈$n的$l",
		210, 15, 5, 35, 32,},
		{"$N侧身滑步而上，一招「风声鹤唳」，欺至$n身前，$w猛砍$n的$l",
		230, 20, 5, 50, 45,},
		{"$N快速挥舞$w，使出一招「风中残烛」，幻起一片刀花罩向$n的$l",
		260, 15, 15, 65, 58,},
		{"$N一招「风刀霜剑」，只见漫天刀光闪烁，重重刀影向$n的全身涌去",
		290, 20, 15, 85, 71,},
		{"$N使一招「风驰电掣」，$w舞出阵阵光影向$n的$l涌去",
		320, 40, 10, 105, 86,},
		{"$N一招「风雨飘摇」，$w刀光闪烁不定，似幻似真地逼$n的$l",
		350, 10, 20, 125, 101,},
		{"$N挪步小退，一招「风花雪月」，手中$w轻描淡写地挥出一刀，随即又“唰唰”连劈出两刀，后发先至，洒向$n的$l",
		400, 20, 25, 150, 120,},
	};
	
	int level = me->query_skill("kuangfeng_blade", 1);
	for(int i = 10; i > 0; i--)
		if( action[i - 1].lvl < level)
		{
			level = random(i);
			
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
		
		return & m_actions;
};

virtual int valid_enable(string usage) { return (usage == "blade") || (usage == "parry"); }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 300)
        return notify_fail("你的内力不够。");
	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;
	
    if (!(weapon = me->query_weapon())
        || DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
    if (me->query("hp") < 50)
		return notify_fail("你的体力不够练狂风刀法。");
    me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

