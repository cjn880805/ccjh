//hujia_daofa.h 胡家刀法

SKILL_BEGIN(CShujia_daofa);

virtual void create()
{
	set_name( "胡家刀法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int  force, dodge, parry, lvl, damage;
	}action[8] = {
		{"$N手中$w横推，一招「推波助澜」，由上至下向$nl砍去  ",
			80, -10, 10, 0, 25,},
		{"$N一招「沙鸥掠波」，刀锋自下而上划了个半弧，$w一提一收，平刃挥向$n的颈部  ",
        100, 5, 10, 8, 30,},
		{"$N使出一招「天设牢笼」，将$w舞得如白雾一般压向$n ",
        120, 10, 10, 16, 35,},
		{ "$N一招「闭门铁扇」，$w缓缓的斜着向$n推去 ",
		150, 5, 10, 24, 40,},
		{ "$N手拖$w，转身跃起，一招「翼德闯帐」，一道白光射向$n的胸口 ",
		200, -5, 5, 32, 45,},
		{"$N挥舞$w，使出一招「白鹤舒翅」，上劈下撩，左挡右开，齐齐罩向$n  ",
			230, 10, 5, 40,50,},
		{"$N一招「春风送暖」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l  ",
        300, 5, 10, 48, 60,},
		{ "$N募的使一招「八方藏刀」，顿时剑光中无数朵刀花从四面八方涌向$n全身  ",
        320, 10, 20, 56, 70,},
	};

  	int level = me->query_skill("hujia_daofa", 1);
	for(int i = 8; i > 0; i--)
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

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");
	
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候太浅。");

	if (me->query_skill("force", 1) < 20)
		return notify_fail("你的基本内功火候太浅。");

	return 1;
}


virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够，练不了胡家刀法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;

