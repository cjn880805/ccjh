//throwing.h基本投掷

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSThrowing);

virtual void create()
{
	set_name( "基本投掷");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N扬起$w向$n投去。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp