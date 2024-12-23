//poison.h 基本毒技

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CSpoison);

virtual void create()
{
	set_name( "基本毒技");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn (CChar *me )
{
	char msg[255];
	if ( DIFFERSTR(me->querystr("family/family_name"), "星宿派")
		&&  DIFFERSTR(me->querystr("family/family_name"), "白驼山派")) 
       return notify_fail("你不是星宿弟子，也不是白驼门人，不能修炼毒技。");

    if ((me->query_skill("taoism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1) ||
        (me->query_skill("buddhism",1) > 1))
        return notify_fail(snprintf(msg, 255, "哈哈！%s已经学了名门正派的心法，怎么却来学你们不耻的毒技？", query_respect(me)));
  
	return 1;
}

virtual void skill_improved(CChar * me)
{
    if ((me->query_skill("poison",1) == 50) ||
        (me->query_skill("poison",1) == 60) ||
        (me->query_skill("poison",1) == 70) ||
        (me->query_skill("poison",1) == 80) ||
        (me->query_skill("poison",1) == 90) ||
        (me->query_skill("poison",1) >= 100))
    {
        tell_object(me, "你体内的毒质开始反噬自身了，得找人散毒了。");
        me->apply_condition("poison_sandu",1000);
    }
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp