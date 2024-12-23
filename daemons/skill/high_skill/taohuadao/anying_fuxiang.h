//anying_fuxiang.h 暗影浮香

SKILL_BEGIN(CSanying_fuxiang);

virtual void create()
{
	set_name( "暗影浮香");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[6][80]={	
		{"$n一个「月上柳梢头」，随着$N的攻势飘起，从容躲过这一招。"},
		{"$n使出一招「大漠孤烟直」，猛然纵起丈余，结果$N扑了个空。"},
		{"$n身形一摇，幻出几个人影，一招「碎影舞斜阳」躲过了$N的攻势。"},
		{"$n一招「燕子三抄水」纵身跃起，倏忽已落至$N身后。"},
		{"$n左一摇，右一晃，一招「云深不知处」已轻松闪过。"},
		{"$n双足一点，斜斜飞起，使出「斜日杏花飞」已闪到$N身侧。"},
	};

	return dodge_msg[random(6)];
}

virtual int valid_enable(string usage) { return (usage == "dodge") ; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 30 )
            return notify_fail("你的体力太差了，不能练暗影浮香。");
        if (me->query_skill("yan_shuangfei", 1) < 30)
	        me->receive_damage("hp", 10);
		me->receive_damage("hp", 20);
        return 1;
}

SKILL_END;

