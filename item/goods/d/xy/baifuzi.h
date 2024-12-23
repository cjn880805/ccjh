//baifuzi.h 逍遥任务特殊道具
ITEM_BEGIN(CIbaifuzi)

virtual void create(int nFlag = 0)		
{
	set_name("白附子", "bai fuzi");
	set("long",	"药材。性温，味辛，有毒。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




