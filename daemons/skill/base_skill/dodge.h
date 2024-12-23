// SUnarmed.cpp: implementation of the CSUnarmed class.
//
//////////////////////////////////////////////////////////////////////

//dodge.h -- 基本躲闪

SKILL_BEGIN(CSDodge);

virtual void create()
{
	set_name( "基本躲闪");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80] = 
	{
		"但是和$p$l偏了几寸。",
		"但是被$p机灵地躲开了。",
		"但是$n身子一侧，闪了开去。",
		"但是被$p及时避开。",
		"但是$n已有准备，不慌不忙地躲开。",
	};
	
	return dodge_msg[random(5)];
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));

	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

/*	if(who1 && me->query_skill("dodge", 1)>=400)
		return notify_fail("以你伴侣目前的功力，基本躲闪已经无法继续指点了。");
	
	if(me->query_skill("dodge", 1)>=400)
		return notify_fail("以你目前的功力，基本躲闪已经无法继续请教了。");
*/
	return 1;
}

SKILL_END;