// wudu-xinfa

FORCE_BEGIN(CSwudu_xinfa);

virtual void create()
{
	set_name( "五毒心法");
}


virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	if( me->query("repute") < 1000 )
		return notify_fail("修习五毒心法必需心狠手辣才行。");

	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("五毒心法只能靠请教来提高。");
}

FORCE_END;