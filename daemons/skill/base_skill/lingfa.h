//lingfa.h基本令法

//coded by Cat
//data: 2001-3-21

SKILL_BEGIN(CSlingfa);

virtual void create()
{
	set_name( "基本令法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N挥舞$w拍在$n的身上。");
	return & m_actions;
}

virtual int valid_learn(CChar * me)
{

	if (me->query_skill("lingfa", 1) > 330 && !me->query("mj/linfa"))
		return notify_fail("你的基本令法已经达到了一定的火候，已经不能在师傅这里继续请教了。");

	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp



