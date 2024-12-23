//celestrike.h  虎掌

//coded by Fisho
//data: 2000-11-1

SKILL_BEGIN(CScelestrike);

virtual void create()
{
	set_name( "虎掌");
}

virtual CMapping * query_action(CChar * me)
{
	struct{
			char action[100];
			int dodge, parry, force, damage;
			char damage_type[5];
	}action[]={
		{"$N使出一招「天虎扑式」，右掌穿出击向$n的$l。",-30,10,100,100,"瘀伤",},
		{"$N使出一招「天虎剪式」，左掌化虚为实击向$n的$l。",-10,-30,100,120,"瘀伤",},
		{"$N使出虎掌中「天虎扫式」，如猛虎般欺至$n身前，一掌拍向$n的$l。",-30,10,70,140,"瘀伤",},
		{"$N双掌一错，使出「天虎擒式」，对准$n的$l连续拍出三掌。",10,-30,130,140,"瘀伤",},
		{"$N左掌画了个圈圈，右掌推出，一招「天虎啜式」击向$n$l。",-20,-30,200,120,"瘀伤",},
		{"$N使出「天虎七式」，身形散作七处同时向$n的$l出掌攻击。",-70,-10,240,110,"瘀伤",},
		{"$N吐气扬声，一招「九重天虎」双掌并力推出。",-70,-40,350,100,"瘀伤",},
	};
		
	int level = random(7);

	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	m_actions.set("parry", action[level].parry);
	m_actions.set("force", action[level].force);
	m_actions.set("damage", action[level].damage);
		
	return & m_actions;
}

virtual const char * query_parry_msg(CContainer * weapon)
{
	static char parry_msg[][255] = {
		{"$n化掌为刀，一招「碧血五指挑」急切$N拿着$w的手。"},
		{"$n双掌交错，使出一招「童子拜寿」，「啪」的一声将$N的$w夹在双掌之间。"},
		{"$n略一转身，一招「兵出无名」拍向$N拿着$w的手。"},
		{"$n使出「粘」字诀，双掌一划，引偏了$N的$w。"},
		{"$n步走七星，一招「反客为主」虚空拍出十三掌，逼得$N撤招自保。"},
        {"$n化掌为指，一招「掌指双飞」反点$N的周身要穴。"},
        {"$n施展出「掌指双飞」，轻描淡写的化解了$N的攻势。"},
	}; 
	if( weapon )
		return parry_msg[random(4)];
	else
		return parry_msg[random(3)+4];
}


int valid_learn(CChar * me)
{
    if( me->query_weapon())
         return notify_fail("练虎掌必须空手。");

    return 1;
}

int valid_enable(string usage)
{
	return usage=="unarmed" || usage=="strike" || usage == "parry";
}


int practice_skill(CChar * me)
{
	if( me->query("hp") < 30 )
     return notify_fail("你现在手足酸软，休息一下再练吧。");
   
	if( me->query("mp") < 10 )
		return notify_fail("你的内力不够了。");

	me->receive_damage("hp", 30);
	me->add("mp", -10);

	return 1;
}

protected:
	CMapping m_actions;

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp

