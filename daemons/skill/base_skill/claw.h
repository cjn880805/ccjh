//claw.h����צ��

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSclaw);

virtual void create()
{
	set_name( "����צ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N�����ָצ��$n�����ϡ�");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp