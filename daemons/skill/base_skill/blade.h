//blade.h基本刀法

SKILL_BEGIN(CSBlade);

virtual void create()
{
	set_name( "基本刀法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w砍在$n的脑袋上。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp