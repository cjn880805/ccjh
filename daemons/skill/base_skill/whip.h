//whip.h�����޷�

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSWhip);

virtual void create()
{
	set_name( "�����޷�");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w����$n�����ϡ�");
	m_actions.set("dodge", -20);
	m_actions.set("parry", 30);
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp