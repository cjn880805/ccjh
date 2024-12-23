
// shenlong_xinfa.h 神龙心法
//code by Fisho
//date : 2000-12-08

SKILL_BEGIN(CSshenlong_xinfa);

virtual void create()
{
	set_name( "神龙心法");
}

virtual int valid_enable(string usage) { return usage == "force"; }

virtual int practice_skill(CChar * me)
{
	return notify_fail("神龙心法只能靠请教来提高。");
}

virtual int valid_learn(CChar * me)
{
	int i = me->query_skill("shenlong_xinfa", 1);
	int t = 1, j;

	if( i <= 100)
		for (j = 1; j < i / 10; j++)
			t*= 2;

	if ( EQUALSTR(me->querystr("gender"), "无性") && i > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的神龙心法。");
	if (me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候不足，不能学神龙心法。");

	if(i<=100)
	{
		if (i > 10 && -me->query("repute") < t * 100) 
			return notify_fail("学神龙心法，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}
	else
	{
		if (-me->query("repute") < (51200 + (i - 100) * 1000)) 
			return notify_fail("学神龙心法，要心狠手辣，奸恶歹毒，你可做得不够呀！");
	}

	if ( me->query_skill("bibo_shengong",1)
	|| me->query_skill("beiming_shengong",1)
	|| me->query_skill("bahuang_gong",1)
	|| me->query_skill("hamagong",1)
	|| me->query_skill("huagong_dafa",1)
	|| me->query_skill("huntian_qigong",1)
	|| me->query_skill("hunyuan_yiqi",1)
	|| me->query_skill("longxiang",1)
	|| me->query_skill("jiuyang_shengong",1)
	|| me->query_skill("taiji_shengong",1)
	|| me->query_skill("xiaowuxiang",1)
	|| me->query_skill("yunlong_shengong",1)
	|| me->query_skill("zixia_shengong",1) )
		return notify_fail("你不先散了别派内功，怎能学神龙心法？！");

	return 1;
}

SKILL_END;
