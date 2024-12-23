//xinren.h 逍遥任务特殊道具
ITEM_BEGIN(CIxinren)

virtual void create(int nFlag = 0)		
{
	set_name("杏仁", "xin ren");
	set("long",	"杏仁有苦甜之分，俱是药材，性质两异。");
	set("unit", "支");
	set_weight(1000);
	set("value", 380000);
};

ITEM_END;




