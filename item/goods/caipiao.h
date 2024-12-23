//yinpiao.h 银票
//muri 2004-10-23

ITEM_BEGIN(CIcaipiao)

void create(int nFlag = 0)	
{
	set_name("彩票", "cai piao");
	set_weight(100);
    set("value", 10);

	char msg[255];
	if(query("number"))
		set("long",snprintf(msg, 255,  "这是苏州聚宝斋开出的一张彩票，编号为：%d。",query("number")));
	else
		set("long", "这是苏州聚宝斋开出的一张过期彩票。");
	set("unit", "张");	
}


ITEM_END;
