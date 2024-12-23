//jinyan_gong.h 金雁功

SKILL_BEGIN(CSjinyan_gong);

virtual void create()
{
	set_name( "金雁功");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[8][120]={	
		{"$n身形晃动，使出一招出有入无，似左实右，忽前忽后，若有若无的闪过$N的攻击。"},
		{"$n突然身子一缩，一招藏形匿迹，人已在三尺之外。"},
		{"可是$n一招飞灵八方猛然纵起丈余，身形晃动，躲过了$N的攻势。"},
		{"只见$n左走三步，又向右斜跨两步，一招隐景舞天，不知怎的$n已经到了$N的身后。"},
		{"$n不住倒退，忽然身形晃动，一招解行遁变转到了$N的身侧。"},
		{"$n身随意走，一招弃厄飞霄躲过了$N的凌厉攻势。"},
		{"$n脚下一点，一招回神转玄斜斜的飞出恰巧躲开了$N的进攻。"},
		{"$n一招乘虚御空侧身一让，$N这招扑了个空。"},
	};

	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) { return usage == "dodge"; }

virtual int valid_learn(CChar * me)
{
    return 1;
}

virtual int practice_skill(CChar * me)
{
        if( me->query("hp") < 40 )
                return notify_fail("你的体力太差了，不能练金雁功。");
        me->receive_damage("hp", 30);
        return 1;
}

SKILL_END;

