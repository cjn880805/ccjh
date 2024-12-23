
// xiaoyaoyou.h 逍遥游
//code by Fisho
//date : 2000-12-02

SKILL_BEGIN(CSxiaoyaoyou);

virtual void create()
{
	set_name( "逍遥游");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]=
	{
		"$n一个「蜻蜓点水」，躲过了$N这一招。",
		"$n身形向后一纵，使出一招「细胸巧翻云」，避过了$N的攻击。",
		"$n使出「虚怀若谷」，恰好躲过了$N的攻势。"
	};
	
	return dodge_msg[random(3)];
}

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge") || (usage == "move"); 
}

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练逍遥游。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
