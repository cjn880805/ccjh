//blade.h��������

SKILL_BEGIN(CSBlade);

virtual void create()
{
	set_name( "��������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w����$n���Դ��ϡ�");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp