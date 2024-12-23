SKILL_BEGIN(CScibei_dao);

virtual void create()
{
	set_name( "慈悲刀");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去",
			120, -10, 0, 0,},
		{"$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部",
		130, -10, 5, 8,},
		{"$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n",
		140, -5, 15, 16,},
		{"$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n",
		160, 5, 25, 24,},
		{"$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口",
		180, 10, 30, 33,},
		{"$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n",
		210, 15, 35, 42,},
		{"$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l",
		240, 5, 50, 51,},
		{"$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去",
		280, 20, 60, 60,},
		};
	
	int level = me->query_skill("cibei_dao", 1);
	for(int i = 8; i > 0; i--)
		if(level > action[i-1].lvl)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);

			break;
		}
	
	return & m_actions;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练慈悲刀。");

	me->receive_damage("hp", 25);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力不够。");

	if (me->query_skill("hunyuan_yiqi", 1) < 10)
		return notify_fail("你的混元一气功火候太浅。");

	return 1;
}

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry";}
virtual int valid_combine(string combo) { return combo=="fumo_jian"; }

SKILL_END;