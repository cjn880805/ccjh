//lingfa.h�����

//coded by Cat
//data: 2001-3-21

SKILL_BEGIN(CSlingfa);

virtual void create()
{
	set_name( "�����");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N����$w����$n�����ϡ�");
	return & m_actions;
}

virtual int valid_learn(CChar * me)
{

	if (me->query_skill("lingfa", 1) > 330 && !me->query("mj/linfa"))
		return notify_fail("��Ļ�����Ѿ��ﵽ��һ���Ļ���Ѿ�������ʦ�������������ˡ�");

	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp



