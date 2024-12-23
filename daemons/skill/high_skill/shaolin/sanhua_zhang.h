SKILL_BEGIN(CSsanhua_zhang);

virtual void create()
{
	set_name( "散花掌");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[4] = {
		{ "$N合掌抱球，一式「春深芳草尽」，双掌变幻吞吐，缓缓推向$n的$l",
			180, 5, 20, 10, 0,},
		{ "$N五指绽开，一式「夏闲独兰馨」，左右掌穿插翻飞，疾向$n的$l拍去",
		260, 10, 15, 20, 20,},
		{ "$N使一式「秋酣菊霜清」，左掌虚托，右掌乍伸乍合，猛地插往$n的$l",
		340, 15, 20, 30, 40,},
		{ "$N双掌血红，一式「冬卧听梅吟」，幻成漫天梅花朵朵，雨点般向$n击去",
		420, 20, 30, 40, 60,},
	};

	int level = me->query_skill("sanhua_zhang", 1);
	for(int i = 4; i > 0; i--)
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

	return notify_fail("散花掌必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练散花掌。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练散花掌必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学散花掌。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练散花掌。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="nianhua_zhi"; }

SKILL_END;