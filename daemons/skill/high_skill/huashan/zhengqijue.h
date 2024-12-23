
// zhengqijue.h 正气决
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSzhengqijue);

virtual void create()
{
	set_name( "正气决");
}
virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("正气决只能靠请教来提高。");
}

virtual void skill_improved(CChar *me)
{
	int lvl = me->query_skill("zhengqijue", 1);

	if(lvl > 10)
	{
		tell_object(me, "你心里鼓荡着一股侠义之气！"   );
	    me->add("repute", 5);
	}
}

SKILL_END;
