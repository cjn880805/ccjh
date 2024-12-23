//yiyang_zhi.h  一阳指

SKILL_BEGIN(CSyiyang_zhi);

virtual void create()
{
	set_name( "一阳指");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("一阳指必须与大理独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
		char weapon[10],damage_type[5];
	}action[] = {
		{"$N双指并拢，一式「佛恩济世」，和身而上，左右手一前一后戳向$n的胸腹间", 60, -5, -5, 10, 0, "无形剑气","刺伤",},
		{"$N左掌护胸，一式「佛光普照」，右手中指前后划了个半弧，猛地一甩，疾点$n的$l", 120, 5, 10, 20, 10, "无形剑气","刺伤",},
		{"$N身形闪动，一式「佛门广渡」，双手食指端部各射出一道青气，射向$n的全身要穴", 180, 10,20 , 30, 20, "无形剑气","刺伤",},
		{"$N盘膝跌坐，一式「菩提悟佛」，左手握拳托肘，右手拇指直立，遥遥对着$n一捺", 240, 20, 30, 40, 30, "无形剑气","刺伤",},
		{"$N忽地跃起，左掌抚胸，右手伸出食指，一式「佛法无边」缓缓向$n头顶百汇穴点去", 300, 30, 40, 50, 40, "无形剑气","刺伤",},
		{"$N一式「佛现灵山」，出指舒缓自如，收臂潇洒飘逸，对着$n一捺", 360, 40, 50, 60, 50, "无形剑气","刺伤",},
		{"$N手臂颤动，有如蜻蜒点水，一招「观音济世」，拂遍$n全身诸穴", 420, 40, 50, 70, 60, "无形剑气","刺伤",},
		{"$N倏忽之间欺近身去，一招「佛光轻逝」点向$n，一攻而退，鱼逝兔脱，灵动无比", 480, 60, 60,90 , 80, "无形剑气","刺伤",},
	};

	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("yiyang_zhi", 1))
		{
			int level = random(i);
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

virtual int valid_enable(string usage) { return usage=="finger" || usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon())
		return notify_fail("练一阳指必须空手。");
 
	if (me->query("max_mp") < 150)
		return notify_fail("你的内力太弱，无法练一阳指。");
	if (me->query_skill("force",1)<20)
		return notify_fail("你的基本内功火候不到，无法练这门功夫。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够了。");
	
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;

/*********
int enable_factor() { return 20; }

int learn_bonus() { return 10; }

int practice_bonus() { return 10; }

int study_bonus() { return 10; }
********/