//claw.h基本爪法

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSclaw);

virtual void create()
{
	set_name( "基本爪法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N伸出五指爪在$n的脸上。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp