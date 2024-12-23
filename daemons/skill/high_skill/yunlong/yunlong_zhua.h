// yunlong-zhua.c -云龙爪
SKILL_BEGIN(CSyunlong_zhua);

virtual void create()
{
	set_name( "云龙爪");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int force, dodge, parry, damage ,lvl;
	}action[] = {
		{"$N全身拔地而起，半空中一个筋斗，一式「凶鹰袭兔」，迅猛地抓向$n的$l", 150,15,10,10,0,},
		{"$N单腿直立，双臂平伸，一式「雄鹰展翅」，双爪一前一后拢向$n的$l", 220, 20, 15, 15, 10,},
		{"$N一式「拔翅鹰飞」，全身向斜里平飞，右腿一绷，双爪搭向$n的肩头", 250, 20, 20, 20, 20,},
		{"$N双爪交错上举，使一式「迎风振翼」，一拔身，分别袭向$n左右腋空门", 290, 25, 20, 30, 30,},

		{"$N全身滚动上前，一式「飞龙献爪」，右爪突出，鬼魅般抓向$n的胸口", 350, 30, 25, 40, 40,},
		{"$N伏地滑行，一式「顶天立地」，上手袭向膻中大穴，下手反抓$n的裆部", 350, 35, 25, 50, 50,},
		{"$N左右手掌爪互逆，一式「搏击长空」，无数道劲气破空而出，迅疾无比地击向$n", 380, 55, 55, 65, 60,},
		{"$N腾空高飞三丈，一式「鹰扬万里」，天空中顿时显出一个巨灵爪影，缓缓罩向$n", 430, 40, 40, 60, 70,},
		
		{"$N忽的拨地而起，使一式「苍龙出水」，身形化作一道闪电射向$n", 470, 50, 50, 100, 80,},
		{"$N微微一笑，使一式「万佛朝宗」，双手幻出万道金光,直射向$n的$l", 470, 60, 60, 100, 90,},
	};
	
	int level = me->query_skill("yunlong_zhua", 1);
	for(int i=10; i>0; i--)
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
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练云龙爪。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

virtual int valid_enable(string usage) { return usage == "unarmed" || usage == "claw"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练云龙爪必须空手。");
	if (me->query_skill("yunlong_shengong", 1) < 20)
		return notify_fail("你的云龙神功火候不够，无法学云龙爪。");
	if (me->query_skill("force", 1) < 50)
		return notify_fail("你的基本内功火候不够，无法学云龙爪。");
	if (me->query("max_mp") < 350)
		return notify_fail("你的内力太弱，无法练云龙爪。");
	if (me->query_skill("claw",1) <40)
		return notify_fail("你的基本爪法火候不够，无法学云龙爪。");
	if ( (2*me->query_skill("yunlong_xinfa",1)) <me->query_skill("yunlong_zhua",1))
		return notify_fail("你的云龙爪法火候不够，无法继续学云龙爪。");
	return 1;
}


virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if(me->query_skill("yunlong_shengong") > 70 )
	{
		if( random(me->query_skill("yunlong_zhua")) > 30 )
		{
			victim->apply_condition("zhua_poison", random(me->query_skill("yunlong_zhua")/10 + 1) + 1 +
				victim->query("condition/zhua_poison"));
		}
	}
	
	return 0;
}

virtual int valid_combine(string combo) { return combo=="yunlong_shou"; }

SKILL_END;

/*
mapping *action = ({
});

int valid_combine(string combo) { return combo=="yunlong-shou"; }

*/