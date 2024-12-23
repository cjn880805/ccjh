//tiexue_steps.h 铁血十二势

SKILL_BEGIN(CStiexue_steps);

virtual void create()
{
	set_name( "铁血十二势");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"但是$n身形飘忽，一招「穿云势」拔地而起，举重若轻的避开这一击。"},
		{"$n身随意转，一式「破雾势」，全身化作无数虚影掠出丈外。"},
		{"$n身形往上一拔，一招「开天势」，腾空而起，避了开去。"},
		{"$n气聚丹田，一招「劈地势」，身形急缩，躲开$N那致命一击。"},
		{"$n身形往上一拔，一招「推山势」落在数尺之外。"},
		{"$n身形晃动，一招「搅海势」，全身化作无数虚影掠出丈外。"},
		{"$n真气荡漾，如雷霆般大喝一声，一招「雷针势」，身形极速后退。"},
		{"$n使出「电箭势」，身形如电般地躲开了$N这一招。"},
		{"$n身影微动，已经藉一招「龙腾势」轻轻闪过。"},
		{"$n腾空一跃，双脚向前一踢，一招「虎扑势」，躲开数尺。"},
		{"只见$n身影一晃，一式「豹跃势」早已避在七尺之外。"},
		{"可是$n使一招「鹰飞势」，身子轻轻飘了开去，早已绕到$N身後！"},
	};

	return dodge_msg[random(12)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

