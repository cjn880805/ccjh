//axe.��������

//add by Lanwood
//date:2000-12-28

SKILL_BEGIN(CSaxe);

void create()
{
	set_name( "��������");
}

CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w��$n��ȥ��");
	m_actions.set("dodge", 30);
	m_actions.set("parry", 30);

	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp