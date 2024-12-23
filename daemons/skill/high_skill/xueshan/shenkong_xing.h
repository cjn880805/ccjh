// shenkong-xing.c 身空行

FORCE_BEGIN(CSshenkong_xing);

virtual void create()
{
	set_name( "身空行");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char action[][255] = {
		{"$n使出一招「心空」，身体向侧后飘去"},
		{"$n使出一招「誓言空」，双足一点，跃至数丈之外"},
		{"$n使出一招「莲空」，身形一变，滑至$N身后"},
		{"$n大吼一声，使出一招「大安空」，从$N头顶越过"},
		{"$n使出一招「佛空」，如轻鸿般飘去，瞬间又闪至$N面前"},
		{"$n使出一招「金刚空」，顿时$N周围都是$n的身影"},
	};

	return action[random(6)];
};

virtual int valid_enable(string usage) { return usage=="dodge" ||  usage=="move"; }

virtual int valid_learn(CChar * me){return 1;}

virtual int practice_skill(CChar * me)
{
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练习身空行。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
