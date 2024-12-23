// taiji-dao.c 太极刀

SKILL_BEGIN(CStaiji_dao);

virtual void create()
{
	set_name( "太极刀");
	set("valid_force", "taiji_shengong");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[] = {
		{"$N手中$w斜指，一招「停车问路」，反身一顿，一刀向$n的$l撩去", 120, -10, 5, 15, 0,},
		{"$N一招「童子挂画」，左右腿虚点，$w一提一收，平刃挥向$n的颈部", 120, -10, 5, 15, 10,},
		{"$N展身虚步，提腰跃落，一招「推窗望月」，刀锋一卷，拦腰斩向$n", 140, -5, 5, 25, 20,},
		{"$N一招「开门见山」，$w大开大阖，自上而下划出一个大弧，笔直劈向$n", 160, 5, 5, 30, 30,},
		{"$N手中$w一沉，一招「临溪观鱼」，双手持刃拦腰反切，砍向$n的胸口", 180, 10, 5, 35, 40,},
		{"$N挥舞$w，使出一招「张弓望的」，上劈下撩，左挡右开，齐齐罩向$n", 210, 15, 15, 45, 50,},
		{"$N一招「风送轻舟」，左脚跃步落地，$w顺势往前，挟风声劈向$n的$l", 240, 5, 15, 50, 55,},
		{"$N盘身驻地，一招「川流不息」，挥出一片流光般的刀影，向$n的全身涌去", 280, 20, 10, 60, 60,},
	};

	int level = me->query_skill("taiji_dao", 1);
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < level)
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("parry", action[level].parry);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}

	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="blade" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{

	if (me->query("max_mp") < 100)
		return notify_fail("你的内力不够。");
	
	if (me->query_skill("taiji_shengong", 1) < 20)
		return notify_fail("你的太极神功火候太浅。");
	
	if (me->query_skill("taiji_quan", 1) < 20)
		return notify_fail("你的太极拳火候太浅。");
	
	return 1;
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练太极刀法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
