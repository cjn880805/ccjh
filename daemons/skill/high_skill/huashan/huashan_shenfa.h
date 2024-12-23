// huashan_shenfa.h 华山身法
//code by Fisho
//date : 2000-12-06

SKILL_BEGIN(CShuashan_shenfa);

virtual void create()
{
	set_name( "华山身法");
}

virtual CMapping * query_action(CChar * me)
{
	static CMapping m_actions;
	
	struct {
		char action[255];
		int  dodge;
	}action[] = {
		{"$n一式「巨鹏亮翅」，两臂鹏举如翼，在剌剌风声中，从$N头顶横跃而过。", 10,},
		{"$n一式「风送紫霞」，如一阵清风，舒缓地闪过了$N的凌厉攻势。", 20,},
		{"$n一式「燕回朝阳」，轻盈地一跃，一转眼间便绕到了$N的身后。", 30,},
		{"$n一式「却别苍松」，一转身间，向后飘出近一丈远", 40,},
		{"$n一式「旭日初升」，全身笔直，拔地而起，在半空中一转，已落到几丈远的地方。", 50,},
		{"$n一式「金雁横空」，身体如一只金雁般行云流水地滑出丈余。", 60,},
		{"$n一式「晚月朗星」，双脚点地，全身化为一道白影，急速绕着$N打了几转。", 70,},
		{"$n一式「幻眼云湮」，身形陡地变得飘忽不定，令$N无法看清。", 80,},
		{"$n一式「苍龙盘岭」，宛若一条矫矢苍龙，围着$N急速地盘旋了几圈。", 90,},
	};
 	int zhaoshu, level;
	zhaoshu = 9;
	level   =   me->query_skill("huashan_shenfa", 1);
	if (level < 80 )
		zhaoshu--;
	if (level < 60 )
		zhaoshu--;
	if (level < 40 )
		zhaoshu--;
	level =random(zhaoshu);
	
	m_actions.set("action", action[level].action);
	m_actions.set("dodge", action[level].dodge);
	return & m_actions;
};

virtual const char * query_dodge_msg(CChar * me)
{
	CMapping * m = query_action(me);
	return m->querystr("action");
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
	if(  me->query("hp") < 40 )
		return notify_fail("你的体力太差了，不能练华山身法。");
	me->receive_damage("hp", 30);
	return 1;
}

SKILL_END;
