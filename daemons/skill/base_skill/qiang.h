//qiang.h基本枪法

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSqiang);

virtual void create()
{
	set_name( "基本枪法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w向$n刺去。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp