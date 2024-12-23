//lm_shangyang.h  六脉神剑之食指商阳剑

SKILL_BEGIN(CSlm_shangyang);

virtual void create()
{
	set_name( "六脉神剑之食指商阳剑");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "kurong_changong") || EQUALSTR(arg, "kurong_shengong") || EQUALSTR(arg, "tianlong_shengong"))
		return 1;

	return notify_fail("六脉神剑必须与大理独门内功配合使用。");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;

	struct {
		char action[255];
		int force, dodge, parry, damage, lvl;
		char weapon[10],damage_type[5];
	}action[] = {
		{"$N一式「青松迎客」，和身而上，食指戳向$n的胸腹间", 60, -5, -5, 10, 0,"无形剑气","刺伤",},
		{"$N左掌护胸，一式「佛光普照」，食指前后划了个半弧，猛地一甩，疾点$n的$l", 120, 5, 10, 20,10 ,"无形剑气","刺伤",},
		{"$N身形闪动，一式「普渡众生」，食指端部射出一道青气，射向$n的要穴", 180,10 , 20,30 , 20,"无形剑气","刺伤",},
		{"$N盘膝跌坐，一式「菩提悟佛」，左手握拳托肘，右手食指直立，遥遥对着$n一捺", 240, 20, 30, 40, 30,"无形剑气","刺伤",},
		{"$N忽地跃起，左掌抚胸，右手伸出食指，一式「轻点蒲柳」缓缓向$n头顶百汇穴点去", 300, 30,40 , 50, 40,"无形剑气","刺伤",},
		{"$N一式「指点江山」，出指舒缓自如，对着$n一捺", 360, 40, 50, 60, 50,"无形剑气","刺伤",},
		{"$N手臂颤动，有如轻风吹过，一招「微风轻拂」，拂遍$n全身诸穴", 420, 40, 50,70 ,60 ,"无形剑气","刺伤",},
		{"$N倏忽之间欺近身去，一招「佛光轻逝」点向$n，一攻而退，灵动无比", 480, 60, 60, 90, 80,"无形剑气","刺伤",},
	};
    
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("lm_shangyang", 1))
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
	if ( me->query_weapon())
		return notify_fail("练商阳剑必须空手。");
 
	if (me->query("max_mp") < 150)
		return notify_fail("你的内力太弱，无法练商阳剑。");
	
	if (me->query_skill("liumai_shenjian",1)>0)
		return notify_fail("你连六脉合并都能使用了，还想独练一剑？");
	
	if (me->query_skill("sun_finger",1)<50)
		return notify_fail("你的一阳指力还不够！先练好一阳指吧。");
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