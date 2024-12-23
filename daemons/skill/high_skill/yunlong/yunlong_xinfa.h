// yunlong_xinfa.c 云龙心法

FORCE_BEGIN(CSyunlong_xinfa);

virtual void create()
{
	set_name( "云龙心法");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("云龙心法只能靠请教来提高。");
}

FORCE_END;
