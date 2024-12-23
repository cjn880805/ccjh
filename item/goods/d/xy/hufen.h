//hufen.h 逍遥任务特殊道具
ITEM_BEGIN(CIhufen)

virtual void create(int nFlag = 0)		
{
	set_name("胡粉", "hu fen");
	set("long",	"亦称铅白，颜料。相传乃传自西域。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




