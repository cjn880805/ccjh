//sanqi.h 逍遥任务特殊道具
ITEM_BEGIN(CIsanqi)

virtual void create(int nFlag = 0)		
{
	set_name("三七", "san qi");
	set("long",	"三七为常用中药，性温，味辛。具有散瘀止血、消肿定痛之功能。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




