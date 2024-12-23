//whip.h基本鞭法

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSWhip);

virtual void create()
{
	set_name( "基本鞭法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w打在$n的身上。");
	m_actions.set("dodge", -20);
	m_actions.set("parry", 30);
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp