//cuff.h����ȭ��

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CScuff);

virtual void create()
{
	set_name( "����ȭ��");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$Nһȭ����$n�����ϡ�");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp