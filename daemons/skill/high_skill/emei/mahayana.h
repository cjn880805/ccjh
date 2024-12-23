
// mahayana.h 大乘涅磐功
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSmahayana);

virtual void create()
{
	set_name( "大乘涅磐功");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn(CChar * me)
{
	char msg[255];

	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
    
	if (DIFFERSTR(me->querystr("family/family_name"), "峨嵋派"))
       return notify_fail("你不是峨嵋弟子，不能修炼大乘涅磐功。");

    if (me->query("repute") < 0 )
       return notify_fail("你的邪气太重，无法修炼大乘涅磐功。");

    if(me->query_skill("taoism",1) > 1)
       return notify_fail(snprintf(msg, 255, "哈哈！%s学了牛鼻子的功夫，怎么却来学大乘涅磐功？", query_respect(me)));
    if( me->query_skill("poison",1) > 1 )
      return notify_fail("你学了邪门毒技，无法修炼大乘涅磐功。");

    return 1;
}


SKILL_END;




