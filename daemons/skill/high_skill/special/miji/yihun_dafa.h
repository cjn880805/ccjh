
// yihun_dafa.h 移魂大法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CSyihun_dafa);

virtual void create()
{
	set_name( "移魂大法");
}

virtual int valid_learn(CChar * me)
{
	int lvl;
	
	lvl =  me->query_skill("yihun_dafa", 1);
	
	if(  me->query("repute") < 0 )
		return notify_fail("你的邪气太重，无法修炼移魂大法。");
	
	if (  me->query("per") < 20)
		return notify_fail("就凭你这惨不忍睹的形象？。");
	
	if(EQUALSTR(me->querystr("gender"), "女性"))
	{
		if(lvl>me->query("per")*15)
			return notify_fail("你就只能学到这里了。");
	}
	else
	{
		if(lvl>me->query("per")*5)
			return notify_fail("你就只能学到这里了。");
	}
	return 1;
	
}

virtual int practice_skill(CChar * me)
{	
	return notify_fail("移魂大法只能靠学习来提高。");
}

SKILL_END;
