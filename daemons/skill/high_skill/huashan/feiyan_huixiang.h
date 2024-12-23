//feiyan_huixiang.h 飞燕回翔

SKILL_BEGIN(CSfeiyan_huixiang);

virtual void create()
{
	set_name( "飞燕回翔");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{  "但是$n身形飘忽，轻轻一纵，一招「乳燕投林」，举重若轻的避开这一击。"},
		{"$n身随意转，一式「雪花飞舞」，倏地往一旁飘开数尺，避过了这一招。"},
		{"可是$n侧身一让，使出「柳絮轻飘」，$N这一招扑了个空。"},
		{"却见$n足不点地，一招「腾云驾雾」，身形滴溜溜一转，往旁闪开数尺，躲了开去。"},
		{"$n左脚一点右脚背，身形往上一拔，一招「一鹤冲天」，轻轻巧巧地避开了这一招。"},
		};

	return dodge_msg[random(5)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
    if( me->query("hp") < 30 )
		return notify_fail("你的体力太差了，不能练飞燕回翔......");

	me->receive_damage("hp", 30);
    return 1;
}

SKILL_END;

