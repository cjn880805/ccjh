//strike.h基本掌法

//code by Fisho
//date:2000-11-27

SKILL_BEGIN(CSstrike);

virtual void create()
{
	set_name( "基本掌法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	m_actions.set("action", "$N一掌打在$n的身上。");
	return & m_actions;
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
	
/*	if(who1 && me->query_skill("strike", 1)>=300)
		return notify_fail("以你伴侣目前的功力，基本掌法已经无法继续指点了。");

	if(me->query_skill("strike", 1)>=300)
		return notify_fail("以你目前的功力，基本掌法已经无法继续请教了。");
*/
	return 1;
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp