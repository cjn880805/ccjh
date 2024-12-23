//dagger.h基本短兵

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSdagger);

virtual void create()
{
	set_name( "基本短兵");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w砍在$n的身上。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp