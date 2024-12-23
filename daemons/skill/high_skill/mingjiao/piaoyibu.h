//piaoyibu.h 飘逸步

SKILL_BEGIN(CSpiaoyibu);

virtual void create()
{
	set_name( "飘逸步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$n一个「银鹭渡海」，跃起数尺，躲过了$N这一招。"},
        {"$n身形向后一纵，使出一招「玉兔落尘」，避过了$N的攻击。"},
        {"$n使出「锦鲤穿沙」，恰好躲过了$N的攻势。"},
        {"$n一招「灵狐幻遁」，姿态美妙地躲了开去。"},
	};

	return dodge_msg[random(4)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
                return notify_fail("你的体力太差了，不能练飘逸步法。");
        if (me->query_skill("piaoyibu", 1) < 30)
                me->receive_damage("hp", 10);
        else if (me->query_skill("piaoyibu", 1) < 60)
                me->receive_damage("hp", 20);
        else
                me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

