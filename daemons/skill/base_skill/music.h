//music.h 音律之术

SKILL_BEGIN(CSmusic);

void create()
{
	set_name( "音律之术");
}

CMapping * query_action(CChar * me)
{
	static CMapping m;
	
	m.set("action", "$N拿着$w，向$n冲去。");
	m.set("dodge", -20);
	m.set("damage", 1);
	
	return & m;
}

virtual int valid_learn(CChar * me)
{

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");

/*	if(who1 && me->query_skill("music", 1)>=300)
		return notify_fail("以你伴侣目前的功力，音律之术已经无法继续指点了。");
	
	if(me->query_skill("music", 1)>=300)
		return notify_fail("以你目前的功力，音律之术已经无法继续请教了。");
*/
	return 1;
}

SKILL_END;



