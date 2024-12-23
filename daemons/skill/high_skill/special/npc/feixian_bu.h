//feixian_bu.h 飞仙步法

SKILL_BEGIN(CSfeixian_bu);

virtual void create()
{
	set_name( "飞仙步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$n一招「天玑离枢」轻轻巧巧地避了开去。"},
		{"只见$n身影一晃，一式「天璇乱步」早已避在七尺之外。"},
		{"$n使出「倒转天权」，轻轻松松地闪过。"},
		{"$n左足一点，一招「逐影天枢」腾空而起，避了开去。"},
		{"可是$n使一招「风动玉衡」，身子轻轻飘了开去。"},
		{"$n身影微动，已经藉一招「开阳薄雾」轻轻闪过。"},
		{"但是$n一招「瑶光音迟」使出，早已绕到$N身後！"},
	};

	return dodge_msg[random(7)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

