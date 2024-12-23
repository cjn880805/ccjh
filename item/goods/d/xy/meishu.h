//meishu.h 逍遥任务特殊道具
ITEM_BEGIN(CImeishu)

virtual void create(int nFlag = 0)		
{
	set_name("梅树", "mei shu");
	set("long",	"这是一株傲霜雪而独开的寒梅，树上已开满了鲜红的梅花，清晨的露珠在花瓣上跃动，闪烁着晶莹的光茫。");
	set("unit", "株");
	set_weight(1000);
	set("no_get", "你以为你是鲁智深？");
	set("lushuei",30);
};

ITEM_END;




