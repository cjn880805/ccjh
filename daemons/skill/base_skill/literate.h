//literate.h����д��

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSliterate);

virtual void create()
{
	set_name( "����д��");
}

virtual int valid_learn ( CChar *me )
{
	return 1;
}

virtual const char * type() { return "knowledge"; }

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp