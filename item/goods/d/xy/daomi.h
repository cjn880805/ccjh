//daomi.h 逍遥任务特殊道具
ITEM_BEGIN(CIdaomi)

virtual void create(int nFlag = 0)		
{
	set_name("稻米", "dao mi");
	set("long",	"这是一粒米。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




