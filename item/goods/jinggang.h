//金刚魔咒
//jing_gang.h
//2001-03-26

ITEM_BEGIN(CIjing_gang);

virtual void create(int nFlag = 0)		
{
	set_name("金刚魔咒", "jing_gang");
	set("value", 1);
	set("weight", 100);

};

virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	char msg[255];
	me->add("mp", -50);
	if(me->query("level")>=80 && me->query("food/jing_gang")<100)
	{
		message_vision("$YEL$N掏出一张金刚魔咒，嘴中叽里咕噜的一阵乱念，眉头间青气瞬间一闪，似乎领悟了些什么。", me);
		me->add("combat_exp", 3000);
		me->add("repute",-3000);
		me->add("food/jing_gang",1);
		me->FlushMyInfo();
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "$HIR%s(%s)使用了金刚魔咒，累计使用了%ld次金刚魔咒!", me->name(1), me->id(1), me->query("food/jing_gang")));
	}
	else
	{
		message_vision("$YEL$N掏出一张金刚魔咒，嘴中叽里咕噜的一阵乱念，旁人只见$N读的满头大汗却不知所云，不由哄堂大笑。", me);
	}
	destruct(this);
	return 1; 
}

ITEM_END;




