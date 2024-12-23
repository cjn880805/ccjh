//fengyu_bu.h 风雨飘香步

SKILL_BEGIN(CSfengyu_bu);

virtual void create()
{
	set_name( "风雨飘香步");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][80]={	
		{"$n一声大喝使出「风生万马间」，幻出满天掌影，将$N所有招式化于无形。"},
		{"$n使出一招「冥冥鸟去迟」，猛然纵起丈余，结果$N扑了个空。"},
		{"$n一个「漠漠帆来重」，随着$N的攻势飘起，从容躲过这一招。"},
		{"$n双足一点，斜斜飞起，使出「皎皎孤月轮」已闪到$N身侧。"},
		{"$n身形一摇，幻出几个人影，一招「山风吹空林」躲过了$N的攻势。"},
		{"$n一招「千峰同一色」纵身跃起，倏忽已落至$N身后。"},
	};

	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return usage == "dodge" || usage == "move"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

SKILL_END;

