//shexing_diaoshou.h 蛇形刁手

//coded by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSshexing_diaoshou);

virtual void create()
{
	set_name( "蛇形刁手");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	struct {
		char action[255];
		int  force,dodge, damage,lvl;
		char damage_type[5];
	}action[] = {
		{"$N一式「灵蛇出洞」，右手虚晃，左手扬起，突然拍向$n的背后二穴", 90, 10, 0, 0,"瘀伤",},
		{"$N侧身一晃，一式「虎头蛇尾」，左手拿向$n的肩头，右拳打向$n的胸口", 120, 10,0, 10,"瘀伤",},
		{"$N一式「画蛇添足」，右手环拢成爪，一出手就向扣$n的咽喉要害",130 , 20, 5, 20,"瘀伤",},
		{"$N左手虚招，右掌直立，一式「杯弓蛇影」，错步飘出，疾拍$n的面门", 160 , 20, 10, 30,"瘀伤",},
		{"$N使一式「蛇行鼠窜」，左拳上格，右手探底突出，抓向$n的裆部", 200, 30, 15,38 ,"瘀伤",},
		{"$N一式「蛇磐青竹」，十指伸缩，虚虚实实地袭向$n的全身要穴", 310, 40, 25, 51 ,"内伤",},
		{"$N双手抱拳，一式「万蛇汹涌」，掌影翻飞，同时向$n施出九九八十一招", 380, 40, 30, 56,"内伤",},
		{"$N一式「白蛇吐信」，拳招若隐若现，若有若无，急急地拍向$n的丹田", 460, 40, 40, 60,"内伤",},
	};
 	
	int level = 0;
	
	for(int i=8; i>0; i--)
	{
		if(action[i - 1].lvl < me->query_skill("shexing_diaoshou", 1))
		{
			level = random(i);
			m_actions.set("action", action[level].action);
			m_actions.set("force", action[level].force);
			m_actions.set("dodge", action[level].dodge);
			m_actions.set("damage", action[level].damage);
			break;
		}
	}
	
	return & m_actions;
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "hand") || (usage == "parry");
}

virtual int valid_learn(CChar * me)
{
	
	if (me->query_weapon())
		return notify_fail("练蛇形刁手必须空手。");
	if (me->query_skill("huntian_qigong", 1) < 20)
		return notify_fail("你的混天气功火候不够，无法学蛇形刁手。");
	if (me->query("max_mp") < 100)
		return notify_fail("你的内力太弱，无法练蛇形刁手。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	if (me->query("hp") < 30)
		return notify_fail("你的体力太低了。");
	if (me->query("mp") < 20)
		return notify_fail("你的内力不够练蛇形刁手。");
	me->receive_damage("hp", 25);
	me->add("mp", -5);
	return 1;
}

SKILL_END;
