SKILL_BEGIN(CSpudu_zhang);

virtual void create()
{
	set_name( "普渡杖法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[8] = {
		{"$N使一招「黄牛转角」，手中$w自下而上，沉猛无比地向$n的小腹挑去。",
			180, -10, 15, 0,},
		{"$N快步跨出，一招「野马追风」，左手平托$w，右掌猛推杖端，顶向$n的胸口。",
		200, -10, 20, 9,},
		{"$N高举$w，一招「猛虎跳涧」，全身跃起，手中$w搂头盖顶地向$n击去。",
		230, -5, 30, 18,},
		{"$N一招「狮子摇头」，双手持杖如橹，对准$n猛地一搅，如同平地刮起一阵旋风。",
		270, -10, 35, 27,},
		{"$N横持$w，一招「苍龙摆尾」，杖端化出无数个圆圈，凝滞沉重，把$n缠在其中。",
		320, -15, 40, 36,},
		{"$N全身滚倒，$w盘地横飞，突出一招「大蟒翻身」，杖影把$n裹了起来",
		380, 5, 55, 45,},
		{"$N双手和十，躬身一招「胡僧托钵」，$w自肘弯飞出，拦腰向$n撞去。",
		450, -5, 55, 53,},
		{"$N一招「慈航普渡」，$w如飞龙般自掌中跃出，直向$n的胸口穿入。",
		530, -5, 60, 60,},
	};

	int level = me->query_skill("pudu_zhang", 1);
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

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "hunyuan_yiqi") || EQUALSTR(arg, "yijinjing"))
		return 1;

	return notify_fail("普渡杖法必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (! (weapon = me->query_weapon()) 
		|| DIFFERSTR(weapon->querystr("skill_type"), "staff"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练普渡杖法。");
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

virtual int valid_enable(string usage) {return (usage == "staff") || (usage == "parry"); }

SKILL_END;