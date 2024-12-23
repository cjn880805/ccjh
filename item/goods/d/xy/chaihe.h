//shen.h 逍遥任务特殊道具
ITEM_BEGIN(CIchaihe)

virtual void create(int nFlag = 0)		
{
	set_name("柴禾", "chai he");
	set("long",	"这是每家农户只要费些力气便可获得堆积如山的农作物柴禾。");
	set("unit", "堆");
	set_weight(10000);
	set("value", 1);
};

ITEM_END;




