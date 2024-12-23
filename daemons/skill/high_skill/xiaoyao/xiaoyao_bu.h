// xiaoyao-bu.c 逍遥步

FORCE_BEGIN(CSxiaoyao_bu);

virtual void create()
{
	set_name( "逍遥步");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"只见$n一招「风满天」，身形陡然纵起，躲过了$N这一招。"},
			{"$n一式「樱花落」，身形晃动，向一旁飘出，避开了$N这一招。"},
			{"$n一招「过云龙」，身随意转，$N只觉眼前一花，$n已绕至$N的身后。"},
			{"$n使出「柳随风」，一个空心筋斗向后翻出，避开了$N的凌厉攻势。"},
	};
	return action[random(4)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me) {return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练逍遥步。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
