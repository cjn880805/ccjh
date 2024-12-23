// falun_step.h 法轮辟易功
//code by Teapot
//date : 2001-2-06

SKILL_BEGIN(CSfalun_step);

virtual void create()
{
	set_name( "法轮辟易功");
}

virtual const char * query_dodge_msg(CChar * me)
{
	static char dodge_msg[][100]=
	{
        "$n一招“法身无形”，全身化出千百个身影躲闪开了$N这一招。\n",
        "$n气聚丹田，一招“法随心变”，身形急缩，躲开$N那致命一击。\n",
        "$n真气荡漾，清啸连连，一招“逍遥法外”，滑出丈外。\n",
        "$n双脚轻踏九曲，一招“法外生天”，身形无比美妙地荡开数尺。\n",
        "$n使出如意法轮连环八步中的“法轮生现”，身形化实为虚地躲开了$N这一招。\n",
        "$n腾空一跃，双脚凌空虚踏，一招“法身千重”，躲开数尺。\n",
        "$n身形晃动，一招“万法自然”，全身化作无数虚影掠出丈外。\n",
        "$n猛吸一口气，一招“法轮幻妙”，身形以一个无比怪异的姿势扭曲着弹开数尺。\n"
	};
	
	return dodge_msg[random(8)];
}

virtual int valid_enable(string usage) 
{
	return (usage == "dodge");
}

virtual int valid_learn(CChar * me) { return 1; }

virtual int practice_skill(CChar * me)
{
	if(me->query("hp") < 5 )
		return notify_fail("你的体力太差了，不能练法轮辟易功。");
	me->receive_damage("hp", 5);
	return 1;
}

SKILL_END;


