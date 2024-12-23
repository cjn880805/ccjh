
// yufeng_shu.h 御蜂术
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSyufeng_shu);

virtual void create()
{
	set_name( "御蜂术");
}
virtual const char * type() { return "knowledge"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("御蜂术只能靠请教来提高。");
}

SKILL_END;
