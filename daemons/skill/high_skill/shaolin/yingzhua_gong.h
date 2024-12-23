SKILL_BEGIN(CSyingzhua_gong);

virtual void create()
{
	set_name( "鹰爪功");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	static struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
	}action[8] = {
		{"$N全身拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l",
		100, 5, 5, 0, 0,},
		{"$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪一前一后拢向$n的$l",
		120, 10, 10, 5, 10,},
		{"$N一式「拔翅横飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头",
		150, 10, 10, 10, 20,},
		{"$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门",
		190, 15, 15, 15, 30,},
		{"$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口",
		250, 20, 20, 15, 40,},
		{"$N伏地滑行，一式「拨云瞻日」，上手袭向膻中大穴，下手反抓$n的裆部",
		310, 25, 25, 20, 50,},
		{"$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n",
		380, 25, 25, 25, 55,},
		{"$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n",
		470, 40, 40, 30, 60,},
	};

	int level = me->query_skill("yingzhua_gong", 1);
	for(int i = 8; i > 0; i--)
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
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练鹰爪功。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练鹰爪功必须空手。");
	if (me->query_skill("hunyuan_yiqi", 1) < 20)
		return notify_fail("你的混元一气功火候不够，无法学鹰爪功。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练鹰爪功。");
	return 1;
}

virtual int valid_enable(string usage) { return usage=="claw" || usage=="parry";}
virtual int valid_combine(string combo) { return combo=="fengyun_shou";   }

SKILL_END;