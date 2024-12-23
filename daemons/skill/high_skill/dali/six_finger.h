//six_finger.h 六脉神剑
//lanwood 2001-01-04

SKILL_BEGIN(CSsix_finger);

virtual void create()
{
	set_name( "六脉神剑");
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
		int  force, dodge,  damage;
	}action[6] = {
		{ "$N反过手来，双手拇指同时捺出，嗤嗤两声急响，“少商剑”有如石破天惊、风雨大至之势，分指$n膻中和$l",
			350,  50, 500,},
		{ "$N食指连动，手腕园转，“商阳剑”一剑又一剑的刺出，轻灵迅速，奇巧活泼，剑气纵横，$n根本无法看清来路",
			400,100, 400,},
		{ "$N右手中指一竖，“中冲剑”向前刺出。真气鼓荡，嗤然声响，无形剑气直指$n的$l",
		350, 40, 500,},
		{ "$N右手无名指伸出，“关冲剑”剑路拙滞古朴，一股雄浑的内力鼓荡而出，如排山倒海般向$n涌去",
        350, 60, 500,},
		{ "$N左手小指一伸，一条气流从少冲穴中激射而出，“少泽剑”出手入风，指向$n的$l",
		350,  50,  500,},
		{"$N右手反指，小指伸出，真气自少冲穴激荡而出，“少泽剑”横生奇变，从$n意想不到的方向刺向$n的$l",
        350, 40, 500,},
	};
 
  	if (random(me->query_skill("six_finger",1)) > 60 &&
			me->query_skill("kurong_changong",1) > 60 &&
			me->query("mp") > 100)
	{
		me->add("mp", -100);
		m_actions.set("action", "$HIC$N忽然觉得剑谱中的六路剑法一一涌向心头，十指纷弹，此去彼来，连绵无尽。剑气纵横，尘烟四起，六路剑法回转运使，$n顿时心神大乱，但觉全身几处刺痛，几股鲜血从身上标出。忍痛抬头一看，一柱剑气迎面又到");
		m_actions.set("damage", 500);
		return &m_actions;
	}

	int level = random(6);
	
	m_actions.set("action", action[level].action);
	m_actions.set("force", action[level].force);
	m_actions.set("dodge", action[level].dodge);
	if(me->query_temp("apply/加_六脉"))
		m_actions.set("damage", (me->query_temp("apply/加_六脉")+100) * action[level].damage/100);
	else
		m_actions.set("damage", action[level].damage);
						
	return & m_actions;
};

virtual int valid_enable(string usage) { return usage=="finger" ||  usage=="parry"; }

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon() )
           return notify_fail("练六脉神剑必须空手。");
    if (me->query("max_mp") < 1200)
           return notify_fail("你的内力太弱，无法学六脉神剑。");
    if (me->query_skill("kurong_changong",1) < 120)
           return notify_fail("你的枯荣禅功太低，无法学六脉神剑。");
    return 1;
}


virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 50)
           return notify_fail("你的体力太低了。");
    if (me->query("mp") < 50)
           return notify_fail("你的内力不够练六脉神剑。");
    
    me->receive_damage("hp", 40);
    me->add("mp", -30);
    return 1;
}

virtual char * hit_ob(CChar * me, CChar * victim, LONG & damage)
{
	if( damage < 100 )
	{
		damage = 0;
		return 0;
	}

	if( random( damage / 2) > victim->query_str() )
	{
		victim->receive_wound("hp", (damage - 100) / 2 );
		return "你听到「嗤啦」一声轻响，脸上竟溅到一些血滴！";
	}

	return 0;
}

SKILL_END;

