//yinpiao1.h 银票
//muri 2001-11-16

ITEM_BEGIN(CIyinpiao1)

void create(int nFlag = 0)	
{
	set_name("银票", "yin piao");
	set_weight(10000);
    set("value", 150);

	set("unit", "张");	
}

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255,  "这是苏州聚宝斋开出的一张银票，面值%d两。",query("value")*8/10);
	say(msg, me);
	SendMenu(me);
	return 1;
}


ITEM_END;
