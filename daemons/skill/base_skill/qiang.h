//qiang.h����ǹ��

//coded by Fisho
//data: 2000-10-31

SKILL_BEGIN(CSqiang);

virtual void create()
{
	set_name( "����ǹ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w��$n��ȥ��");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp