//stick.h基本棍法

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSStick);

virtual void create()
{
	set_name( "基本棍法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w打在$n的脑袋上。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp