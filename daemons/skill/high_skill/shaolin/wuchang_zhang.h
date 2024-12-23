SKILL_BEGIN(CSwuchang_zhang);

virtual void create()
{
	set_name( "无常杖法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[12] = {
		{"$N微一躬身，一招「庸人自扰」，$w带着刺耳的吱吱声，擦地扫向$n的脚踝",
			100, -10, 5, 15, 0,},
		{"$N一招「想入非非」，右手托住杖端，左掌居中一击，令其凭惯性倒向$n的肩头",
		110, -10, 10, 15, 7,},
		{"$N一招「六神不安」，举起$w乒乒乓乓地满地乱敲，让$n左闪右避，狼狈不堪",
		120, -5, 5, 20, 14,},
		{"$N一招「面无人色」，举起$w，呆呆地盯了一会，突然猛地一杖打向$n的$1",
		130, -5, 5, 20, 20,},
		{"$N将$w顶住自己的胸膛，一端指向$n，一招「心惊肉跳」，大声叫喊着冲向$n",
		140, -15, 15, 30, 25,},
		{"$N一招「行尸走肉」，全身僵直，蹦跳着持杖前行，冷不防举杖拦腰向$n劈去",
		150, 5, -15, 30, 30,},
		{"$N面带戚色，一招「饮恨吞声」，趁$n说话间，一杖向$n张大的嘴巴捅了过去",
		300, -5, 20, 40, 35,},
		{"$N一招「力不从心」，假意将$w摔落地上，待$n行来，一脚勾起，击向$n的$1",
		350, -5, 25, 40, 40,},
		{"$N伏地装死，一招「穷途没路」，一个翻滚，身下$w往横里打出，挥向$n的裆部",
		400, -5, 25, 50, 45,},
		{"$N一招「呆若木鸡」，身不动，脚不移，$w却直飞半空，不偏不倚地砸向$n的$1",
		450, -5, 25, 50, 50,},
		{"$N高举$w，一招「人鬼殊途」，身形如鬼魅般飘出，对准$n的天灵盖一杖打下",
		500, -5, 25, 60, 55,},
		{"$N一招「我入地狱」，单腿独立，$w舞成千百根相似，根根砸向$n全身各处要害",
		550, -5, 25, 60, 60,},
	};

	int level = me->query_skill("wuchang_zhang", 1);
	for(int i = 12; i > 0; i--)
		if(level > action[i-1].lvl)
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
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("无常杖必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练无常杖法。");
	me->receive_damage("hp", 30);
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

virtual int valid_enable(string usage) { return (usage == "staff") || (usage == "parry"); }

SKILL_END;