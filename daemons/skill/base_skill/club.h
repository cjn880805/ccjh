//club.h��������

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSclub);

virtual void create()
{
	set_name( "��������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w��$nɨ��ȥ��");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp