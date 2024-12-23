//array.h基本阵法

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSarray);

virtual void create()
{
	set_name( "基本阵法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N摆出基本阵法向$n攻去。");
	return & m_actions;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp