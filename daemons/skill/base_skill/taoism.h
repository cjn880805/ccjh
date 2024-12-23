//taoism.h道学心法

//code by Fisho
//date:2000-11-29

SKILL_BEGIN(CStaoism);

virtual void create()
{
	set_name( "道学心法");
}

virtual const char * type() { return "knowledge"; }

virtual int valid_learn ( CChar *me )
{
	int lvl;
	
	lvl = me->query_skill("taoism", 1);
	
 	if(EQUALSTR(me->querystr("gender"), "无性") && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。");
		
	if(EQUALSTR(me->querystr("class"), "bonze"))
		return notify_fail("哈哈！%s即入佛门，怎么却来学道家心法？", query_respect(me));
	return 1;
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("道学心法只能靠学习来提高。");
}

SKILL_END;
//last, register the skill into ../server/SkillSetup.cpp