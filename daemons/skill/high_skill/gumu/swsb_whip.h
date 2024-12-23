// swsb_whip.h 三无三不手
//code by cat
//date : 2001-4-2

SKILL_BEGIN(CSswsb_whip);

virtual void create()
{
	set_name( "三无三不手");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一招「无孔不入」，$n身前身後都是$w的影子同时点$n全身各处大穴", 200, 5, 0 ,"刺伤",},
		{"$N一招「无所不至」，手中$w点向$n周身诸处偏门穴道。", 300, 5,50 ,"刺伤",},
		{"$N一招「无所不为」，$w专打$n周身柔弱之处。", 350,15 , 100,"刺伤",},
	};
	
	int level = 0;
	
	for(int i=3; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("swsb_whip", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			break;
		}
	}
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "whip") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	CContainer * weapon;

	if (!(weapon = me->query_weapon()) || DIFFERSTR(weapon->querystr("skill_type"), "whip"))
		return notify_fail("练三无三不手需要一件软兵器。");
	if (me->query("max_mp") < 50)
		return notify_fail("你的内力太弱，无法学习三无三不手。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太差了，不能三无三不手。");
	me->receive_damage("hp", 5);
	return 1;
}



SKILL_END;
