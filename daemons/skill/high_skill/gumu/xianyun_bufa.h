
// xianyun_bufa.h 纤云步法
//code by Fisho
//date : 2000-12-05

SKILL_BEGIN(CSxianyun_bufa);

virtual void create()
{
	set_name( "纤云步法");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][120]=
	{
		{"$n使出 纤云步法 身不倾，脚不移，身体如行云流水般直滑出丈余。" },
		{"$n使出 纤云步法 忽然一弯腰，全身贴地而行，顿时闪过了$N的凌厉攻势。"},
		{"$n使出 纤云步法 足不动，手不抬，一转眼间便绕到了$N的身后。" },
		{"$n使出 纤云步法 一转身间，四面八方飘动着无数个$n的身影，令$N手足无措。"},
		{"$n使出 纤云步法 左踏巽，右转乾，身行一晃，便到几丈远的地方。" },
		{"$n使出 纤云步法 身在空中，左脚在右足上一点，从$N头顶腾空而过。" },
		{"$n使出 纤云步法 长袖一拂，全身化为一道白影，幽幽地从$N头顶飘落。"  },
		{"$n使出 纤云步法 身体如陀螺般急转，登时一股气流涌出，令$N难以动弹。"  },
		{"$n使出 纤云步法 身行倏的从$N的眼前直绕到身后，$N瞪大了两眼，不明所以。" },
		{"$n使出 纤云步法 身行倏的从$N的眼前飘过，长发一甩，潇洒之极。"  },
	};
 	
	return dodge_msg[random(10)];
};

virtual int valid_enable(string usage) 
{ 
	return (usage == "dodge")  ;
}

virtual int valid_learn(CChar * me)
{
	if( me->query_skill("tianluo_diwang",1)<30)
	 	return notify_fail("你的天罗地网势还不够纯熟,不能学习先云步法。");
	if( me->query_skill("seaforce",1)<30)
	 	return notify_fail("你的狂潮心法修为不够,不能练纤云步法。");
	 if(me->query_skill("seaforce",1)<me->query_skill("xianyun_bufa",1))
	 	return notify_fail("你的狂潮心法修为不够了，不能继续学习纤云步法。");
	return 1;
}

virtual int practice_skill(CChar * me)
{
	
	if( me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练纤云步法。");
	me->receive_damage("hp", 20);
	return 1;
}

SKILL_END;
