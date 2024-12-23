//cuff.h基本拳法

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CScuff);

virtual void create()
{
	set_name( "基本拳法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N一拳打在$n的身上。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp