//xueduei.h 逍遥任务特殊道具
ITEM_BEGIN(CIxueduei)

virtual void create(int nFlag = 0)		
{
	set_name("雪人", "xue ren");
	set("long",	"雪停了，却给人间铺上了白色的地毯。农人扫开门前的雪，将雪堆成小丘，孩子们却围着雪堆玩耍。");
	set("unit", "堆");
	set_weight(1000);
	set("value", 1);
	set("no_get"," ");
};

ITEM_END;




