SKILL_BEGIN(CSqianye_shou);

virtual void create()
{
	set_name( "如来千叶手");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, damage, lvl;
	}action[9] = {
		{"$N一式「南海礼佛」，右手虚晃，左手扬起，突然拍向$n的背后二穴",
			100, 10, 0, 0,},
		{ "$N侧身一晃，一式「金玉瓦砾」，左手拿向$n的肩头，右拳打向$n的胸口",
		110, 10, 0, 10,},
		{"$N一式「人命呼吸」，右手环拢成爪，一出手就向扣$n的咽喉要害",
		130, 20, 5, 20,},
		{ "$N左手虚招，右掌直立，一式「镜里观影」，错步飘出，疾拍$n的面门",
		160, 20, 10, 30,},
		{ "$N使一式「水中捉月」，左拳上格，右手探底突出，抓向$n的裆部",
		200, 30, 15, 38,},
		{ "$N双拳挥舞，一式「浮云去来」，两手环扣，拢成圈状，猛击$n的下颌",
		250, 30, 20, 45,},
		{ "$N一式「水泡出没」，十指伸缩，虚虚实实地袭向$n的全身要穴",
		310, 40, 25, 51,},
		{ "$N双手抱拳，一式「梦里明明」，掌影翻飞，同时向$n施出九九八十一招",
		380, 40, 30, 56,},
		{ "$N一式「觉后空空」，拳招若隐若现，若有若无，缓缓地拍向$n的丹田",
		460, 40, 40, 60,},
	};

	int level = me->query_skill("qianye_shou", 1);
	for(int i = 9; i > 0; i--)
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

	return notify_fail("如来千叶手必须与少林独门内功配合使用。");
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if ((int)me->query("mp") < 20)
		return notify_fail("你的内力不够练如来千叶手。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练如来千叶手必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学如来千叶手。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练如来千叶手。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="hand" || usage=="parry"; }
virtual int valid_combine(string combo) {return combo=="longzhua_gong"; }

SKILL_END;