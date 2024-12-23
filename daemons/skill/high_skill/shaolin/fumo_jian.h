SKILL_BEGIN(CSfumo_jian);

virtual void create()
{
	set_name( "伏魔剑");
	set("valid_force", "hunyuan_yiqi");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N一式「穿云势」，剑锋平指，剑势如风，一气呵成横扫$n的腰间",
			120, -10, 25, 0,},
		{ "$N向前跃上一步，左手剑诀，右手$w使出一式「破雾势」直刺$n的$l",
		140, -10, 30, 10,},
		{ "$N拔步挺腰，一式「推山势」，手中$w沉滞无比，缓缓挥剑撞向$n的$l",
		170, 5, 35, 20,},
		{"$N一式「搅海势」，$w自左而右划出一个大弧，平平地向$n的$l挥去",
		190, 5, 40, 30,},
		{ "$N回身拧腰，右手虚抱成圆，一式「开天势」，$w中宫直进，刺向$n的胸口",
		240, 10, 50, 40,},
		{ "$N一式「劈地势」，$w从上至下猛劈，剑锋直出，挟爆裂之声骤然斩向$n的$l",
		280, 5, 60, 49,},
		{ "$N运气施出「雷针势」，$w剑尖逼出一道青芒，闪电般破空射向$n的$l",
		350, 5, 75, 57,},
		{"$N双腿半屈半蹲，一式「龙吞势」，剑尖划出无数圆圈，狂风骤起，笼罩天地",
		400, 5, 90, 64,},	
	};
	
	int level = me->query_skill("fumo_jian", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "sword"))
		return notify_fail("你使用的武器不对。");

	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练伏魔剑。");

	me->receive_damage("hp", 35);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");

	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。");

	return 1;
}

virtual int valid_enable(string usage) {return (usage == "sword") || (usage == "parry"); }
virtual int valid_combine(string combo) { return combo=="cibei-dao"; }

SKILL_END;