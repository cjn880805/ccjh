// mizong-xinfa.c 密宗心法
// by secret
FORCE_BEGIN(CSmizong_xinfa);

virtual void create()
{
	set_name( "密宗心法");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{	
	return notify_fail("密宗心法只能通过请教来提高!");
}

FORCE_END;
