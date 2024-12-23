// lamaism.c 密宗心法
FORCE_BEGIN(CSlamaism);

virtual void create()
{
	set_name( "密宗心法");
}


virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if( me->query_skill("taoism", 1) > 1 )
		return notify_fail("你学了牛鼻子的心法，无法修炼密宗心法。");

	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("密宗心法只能靠请教来提高。");
}

FORCE_END;
