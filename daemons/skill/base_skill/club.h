//club.h基本棍法

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSclub);

virtual void create()
{
	set_name( "基本棍法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w往$n扫过去。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp