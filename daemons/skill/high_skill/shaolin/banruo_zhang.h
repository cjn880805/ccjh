SKILL_BEGIN(CSbanruo_zhang);

virtual void create()
{
	set_name( "般若掌");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int force, dodge, lvl;
	}action[10] = {
		{ "$N前腿踢出，后腿脚尖点地，一式「横空出世」，二掌直出，攻向$n的上中下三路",
			150, 5, 0,},
		{"$N左掌划一半圆，一式「长虹贯日」，右掌斜穿而出，疾拍$n的胸前大穴",
		160, 5, 12,},
		{"$N使一式「云断秦岭」，右掌上引，左掌由后而上一个甩劈，斩向$n的$l",
		170, 5, 18,},
		{"$N左掌护胸，右拳凝劲后发，一式「铁索拦江」，缓缓推向$n的$l",
		185, -5, 24,},
		{"$N使一式「狂风卷地」，全身飞速旋转，双掌一前一后，猛地拍向$n的胸口",
		200, 10, 30,},
		{"$N合掌抱球，猛吸一口气，一式「怀中抱月」，双掌疾推向$n的肩头",
		220, 5, 36,},
		{"$N向上高高跃起，一式「高山流水」，居高临下，掌力笼罩$n的全身",
		240, 20, 42,},
		{"$N使一式「摘星换斗」，劲气弥漫，双掌如轮，一环环向$n的$l斫去",
		270, 10, 48,},
		{"$N两掌上下护胸，一式「翻江搅海」，骤然化为满天掌雨，攻向$n",
		310, 30, 54,},
		{"$N一式「金刚伏魔」，双手合十，对着$n微微一揖，全身内劲如巨浪般汹涌而出",
		360, 10, 60,},
	};
	
	int level = me->query_skill("banruo_zhang", 1);
	for(int i = 10; i > 0; i--)
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
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");

	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练般若掌。");

	me->receive_damage("hp", 25);
	me->add("mp", -5);

	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练般若掌必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学般若掌。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练般若掌。");

	return 1;
}

virtual int valid_enable(string usage) { return usage=="strike" ||  usage=="parry";}
virtual int valid_combine(string combo) { return combo=="yizhi_chan"; }

SKILL_END;