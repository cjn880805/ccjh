//xuedao_xinfa.h 雪刀心法

FORCE_BEGIN(CSxuedao_xinfa);

virtual void create()
{
	set_name( "血刀心法");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	int lvl = me->query_skill("xuedao_xinfa", 1);
	int t = 1, j;

	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;
	
	if ( EQUALSTR(me->querystr("gender"), "无性") && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的血刀心法。");
	
	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。");
	
	if(lvl<=100)
	{
		if (lvl > 10 && me->query("repute") > t * -5) 
			return notify_fail("你的杀气太低了。");
	}

	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("血刀心法只能用请教的来增加熟练度。");
}

FORCE_END;
