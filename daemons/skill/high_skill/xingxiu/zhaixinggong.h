// zhaixinggong.h 摘星功
SKILL_BEGIN(CSzhaixinggong);

virtual void create()
{
	set_name( "摘星功");
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

virtual int valid_learn(CChar * me)
{
	return 1;
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$n一个「天外摘星」，跃起数尺，躲过了$N这一招。",},
		{"$n身形向后一纵，使出一招「飘然出尘」，避过了$N的攻击。",},
		{"$n使出「天狼涉水」，恰好躲过了$N的攻势。",},
		{"$n身随意转，一招「斗转星移」，倏地往一旁挪开了三尺，避过了这一招。",},
		{"$n足不点地，使出「流星赶月」，往旁窜开数尺，躲了开去。",},
		{"$n一招「织女穿梭」，姿态美妙地躲了开去。"},
	};

	return dodge_msg[random(6)];
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
         return notify_fail("你的体力太差了，不能练摘星功。");
	if (me->query_skill("zhaixinggong", 1) < 30)
	     me->receive_damage("hp", 10);
	else if (me->query_skill("zhaixinggong", 1) < 60)
		me->receive_damage("hp", 20);
	else 
		me->receive_damage("hp", 30);
   
	return 1;
}

SKILL_END;