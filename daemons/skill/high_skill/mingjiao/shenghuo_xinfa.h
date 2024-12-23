
// shenghuo_xinfa.h 圣火心法
//code by Fisho
//date : 2000-12-07

SKILL_BEGIN(CSshenghuo_xinfa);

virtual void create()
{
	set_name( "圣火心法");
}

virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("圣火心法只能通过请教来提高!");
}

SKILL_END;
