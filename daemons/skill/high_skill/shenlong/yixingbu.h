
// yixingbu.h 意形步法
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSyixingbu);

virtual void create()
{
	set_name( "意形步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = {
		{"$n漫不经心的向左迈出一步，刚好避过$N的凌厉攻势。"},
		{"可是$n不紧不慢往右走了一步，躲过了$N这一招。"},
		{"但是$n身形飘忽，轻轻一纵，早已避开。"},
		{"$n身随意转，倏地往一旁挪开了三尺，避过了这一招。"},
		{"可是$n侧身一让，$N这一招扑了个空。"},
		{"却见$n足不点地，往旁窜开数尺，躲了开去。"},
		{"$n身形微晃，有惊无险地避开了$N这一招。"},
		{"$n看似无心地信手一拂，肩头微侧,堪堪避过了$N这一招。"},
	};
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move");
}

virtual int valid_learn(CChar * me)
{
	return 1; 
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 50 )
		return notify_fail("你的体力太差了，练不了意形步法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
