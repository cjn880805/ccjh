//qingdie_shenfa.h 轻蝶身法

SKILL_BEGIN(CSqingdie_shenfa);

virtual void create()
{
	set_name( "轻蝶身法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[4][80]={	
		"只见$n一招「蝶舞泉边」，身形飘忽不定，躲过了$N这一招。",
		"$n一式「凭虚临风」，身形晃动，向一旁飘出，避开了$N这一招。。",
		"$n使出「蝶随风飞」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。",
		"$n一招「双香凤蝶」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。",
	};

	return dodge_msg[random(4)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") ; }

virtual int valid_learn(CChar * me)
{
	if(me->query_skill("dodge",1) < 20)
		return notify_fail("你的基本轻功火候不够。");

    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
            return notify_fail("你的体力太差了，不能练轻蝶身法。");
        
		me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

