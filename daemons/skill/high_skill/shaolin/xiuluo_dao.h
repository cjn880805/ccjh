SKILL_BEGIN(CSxiuluo_dao);

virtual void create()
{
	set_name( "修罗刀");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[10] = {
		{"$N藏刀内收，一招「割肉饲鹰」，刀锋自下而上划了个半弧，向$n的$l挥去",
			120, -10, 5, 15, 0,},
		{ "$N左掌虚托右肘，一招「投身饿虎」，手中$w笔直划向$n的$l",
		130, -10, 10, 20, 12,},
		{ "$N一招「斫头谢天」，$w绕颈而过，刷地一声自上而下向$n猛劈",
		140, -5, 5, 25, 18,},
		{ "$N右手反执刀柄，一招「折骨出髓」，猛一挫身，$w直向$n的颈中斩去",
		160, 5, 5, 30, 24,},
		{"$N一招「挑身千灯」，无数刀尖化作点点繁星，向$n的$l挑去",
		180, 10, 5, 35, 30,},
		{ "$N双手合执$w，一招「挖眼布施」，拧身急转，刀尖直刺向$n的双眼",
		210, 15, 15, 40, 36,},
		{ "$N一招「剥皮书经」，手中$w划出一个大平十字，向$n纵横劈去",
		240, 15, 15, 50, 42,},
		{ "$N反转刀尖对准自己，一招「剜心决志」，全身一个翻滚，$w向$n拦腰斩去",
		280, 20, 10, 60, 48,},
		{ "$N一招「烧身供佛」，$w的刀光仿佛化成一簇簇烈焰，将$n团团围绕",
		320, 10, 20, 75, 54,},
		{"$N刀尖平指，一招「刺血满地」，一片片切骨刀气如飓风般裹向$n的全身",
		370, 5, 25, 90, 60,},
	};

	int level = me->query_skill("xiuluo_dao", 1);
	for(int i = 10; i > 0; i--)
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

virtual int practice_skill(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon())
		|| DIFFERSTR(weapon->querystr("skill_type"), "blade"))
		return notify_fail("你使用的武器不对。");
	if (me->query("hp") < 50)
		return notify_fail("你的体力不够练修罗刀。");
	me->receive_damage("hp", 35);
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

virtual int valid_enable(string usage) { return usage == "blade" || usage == "parry";  }
virtual int valid_combine(string combo) {return combo=="damo_jian";  }


SKILL_END;