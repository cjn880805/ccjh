//array.h������

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSarray);

virtual void create()
{
	set_name( "������");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N�ڳ���������$n��ȥ��");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp