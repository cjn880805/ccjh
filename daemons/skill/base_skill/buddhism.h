//buddhism.h禅宗心法

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSbuddhism);

virtual void create()
{
	set_name( "禅宗心法");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn ( CChar *me )
{
	if( me->query("guilty") > 0 )
		return notify_fail("你屡犯僧家数戒，尘俗之心太重，无法修炼禅宗心法。");
    return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("禅宗心法只能靠请教来提高。");
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp