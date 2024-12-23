//shen.h 逍遥任务特殊道具
ITEM_BEGIN(CIshen)

virtual void create(int nFlag = 0)		
{
	set_name("绳", "shen");
	set("long",	"这是一条寻常农家用的草麻绳。");
	set("unit", "根");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




