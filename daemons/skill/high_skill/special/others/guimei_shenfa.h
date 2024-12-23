// guimei-shenfa 鬼魅身法（五毒教）

SKILL_BEGIN(CSguimei_shenfa);

virtual void create()
{
	set_name( "鬼魅身法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
			{"只见$n身影飘忽，闪烁不定，使$N的攻击全部落空。"},
			{"却见$n身形微晃，忽地飘开三尺，躲过了$N的攻击。"},
			{"$n收提气收力，身行急转，轻飘飘的让开了$N的这一招。"},
			{"$n身形如同鬼魅一般，变幻不定，眼花缭乱，让$N无法下手。"},
	};

	return action[random(4)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练鬼魅身法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
