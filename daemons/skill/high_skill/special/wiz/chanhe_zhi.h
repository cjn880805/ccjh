
// chanhe_zhi.h 参合指
//code by oho
//date : 2001-6-02

SKILL_BEGIN(CSchanhe_zhi);

virtual void create()
{
	set_name( "参合指");
}

int valid_force(const char * arg)
{
	if(EQUALSTR(arg, "douzhuan_xingyi") )
		return 1;

	return notify_fail("参合指必须和慕容家的内功相配合。");
}


virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl,damage;
		char damage_type[5];
	}action[] = {
		{"$N一指弹出，无声无息的袭向$n的全身数处大穴，正是参合指的绝招‘奇兵突起’", 100, 5, 0,10 ,"刺伤",},
		{"$N横指聚气，使出‘血肉狼藉’削向$n的胸前",150 , 5, 15, 25,"刺伤",},
		{"$N大喝一声，右手食指全力埒出，一招‘千牛斩缺’划向$n的咽喉", 200, 8, 25, 45,"刺伤",},
		{"$N身法诡异，一式‘荒山血变’，指力成刀从$n后颈斩下。", 280,5 , 65,65 ,"刺伤",},
		{"$N一式‘人命草芥’，并不看对手，任由指力四出纵横乱扫。", 300, 15, 80,80 ,"刺伤",},
		{"$N十指乱点，打得四处尘土飞扬，正是一招‘万户鬼哭’", 330, 20, 100, 90,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=6; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("chuanhe_zhi", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "finger") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	if (me->query_weapon()  )
		return notify_fail("练参合指必须空手。");
	if ( me->query_skill("finger", 1) < 30)
		return notify_fail("你的基本指法根基不扎实，无法练参合指。");
	if ( me->query("max_mp") < 350)
		return notify_fail("你的内力太弱，无法练参合指。");
	if ( me->query_skill("douzhuan_xingyi", 1) < 30)
		return notify_fail("你的斗转星移火候不足，无法练参合指。");
	return 1;
	
}

virtual int practice_skill(CChar * me)
{
	if ( me->query("hp") < 30)
		return notify_fail("你的精太低了。");
	if ( me->query("mp") < 20)
		return notify_fail("你的内力不够练参合指。");
	me->receive_damage("hp", 30);
	me->add("mp", -10);
	return 1;
}

SKILL_END;
