//throwing.h����Ͷ��

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSThrowing);

virtual void create()
{
	set_name( "����Ͷ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w��$nͶȥ��");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp