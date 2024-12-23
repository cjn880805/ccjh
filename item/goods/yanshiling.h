//延时令
//yanshiling.h

ITEM_BEGIN(CIyanshiling);

virtual void create(int nFlag = 0)		
{
	char msg[80];

	set_name("烟雨令", "yan yu ling");
	set("value", 1);
	set("weight", 100);

	int level = nFlag;

	if(! nFlag) level = random(20) + 1;
	set("long", snprintf(msg, 80, "这是一块墨绿色的令牌，使用后可以延长%d分钟的任务时间。", level));
	set("protect", level);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if(me->query("mp")<50)
	{
		tell_object(me, "你的法力不够。");
		return 0; 
	}

	me->add("mp", -50);
	if(me->query("level")>=60 && me->querymap("tradepro") )
	{
		if(me->query("tradepro/quest_time")>current_time)
		{
			char msg[255];
			tell_object(me, snprintf(msg, 255, "$HIG你当前的「仗剑江湖」任务期限时间延长了$HIR %d $HIG分钟。",query("protect")));
			me->add("tradepro/quest_time",query("protect")*60);
		}
		else
		{
			tell_object(me, "$HIG很可惜，你来的太迟了，你的「仗剑江湖」任务已经过期了。");
			return 0; 
		}
	}
	else
	{
		tell_object(me, "$HIG你好奇的拿出令牌使用起来，结果~~~~~，没了！");
	}
	destruct(this);
	return 1; 
}

ITEM_END;




