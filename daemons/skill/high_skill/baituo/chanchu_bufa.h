//chanchu_bufa.h   蟾蜍步法

//code by Fisho
//date : 2000-11-29

SKILL_BEGIN(CSchanchu_bufa);

virtual void create()
{
	set_name( "蟾蜍步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]=
	{
	"只见$n一招「蟾飞九天」，身体向上笔直地纵起丈余，躲过了$N这一招。",
	"但是$n一个使出「蛙鸣震天」，身形飘忽，轻轻一纵，早已避开。",
	 "$n一招「蛙入稻田」，身行随意转，倏地往一旁挪开了三尺，避过了这一招。",
	"可是$n一个「蟾蜍扑虫」，侧身一让，$N这一招扑了个空。",
	"却见$n「蟾翻白肚」，足不点地，往旁窜开数尺，躲了开去。",
	"$n身形一招「金蟾归月」，身形微晃，有惊无险地避开了$N这一招。"
	};
	
	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") || (usage == "move"); }

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 45 )
		return notify_fail("你的体力太差了，不能练蟾蜍步法。");
	me->receive_damage("hp", 35);
	return 1;
}

SKILL_END;