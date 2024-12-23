// zhutian_bu.h 诸天化身步
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSzhutian_bu);

virtual void create()
{
	set_name( "诸天化身步");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
		"只见$n一招「天地钩」，身体腾空，双足向上，笔直地纵起丈余，躲过了$N这一招。",
		"$n身随意转，一式「凤点头」头部前挺，侧身收腹，倏地往一旁挪开了三尺，避过了这一招。",
		"$n双足抓地，身形微晃，一招「鹰爪松」有惊无险地避开了$N这一招。",
		"但是$n身形飘忽，一式「风摆柳」，轻轻一纵，早已避开。",
		"$n一个「阴阳箭」，向后纵出数丈之远，避开了$N的凌厉攻势，立即又欺近$N身旁。",
		"$n使出「日月扣」，双手如钩向一旁飘然纵出，轻轻着地。",
	};
	
	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) 
{
	return (usage == "dodge") || (usage == "move");
}

virtual int valid_learn(CChar * me) 
{
	CChar * who = (CChar *)(me->environment())->present(me->querystr("family/master_id"));
	if(who && who->query("add_skill/count"))
		return notify_fail("你的师傅暂时没空指点你武功。。");

	CChar * who1 = (CChar *)(me->environment())->present(me->querystr("couple/id"));
	if(who1 && who1->query("add_skill/count"))
		return notify_fail("你暂时无法指点你伴侣的武功。。");
	return 1;
 }

virtual int practice_skill(CChar * me)
{
	if(me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练诸天化身步。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;




