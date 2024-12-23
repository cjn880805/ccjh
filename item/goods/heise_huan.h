//heise_huan.h 逍遥任务特殊道具
ITEM_BEGIN(CIheise_huan)

virtual void create(int nFlag = 0)		
{
	set_name("黑色指环", "heise zhihuan");
	set("long",	"这是一枚黑色的指环，看起来没什么起眼的地方。");
	set("unit", "枚");
	set_weight(1000);
	set("value", 1);

};

ITEM_END;




