//daohe.h 逍遥任务特殊道具
ITEM_BEGIN(CIdaohe)

virtual void create(int nFlag = 0)		
{
	set_name("稻禾", "dao he");
	set("long",	"这是一簇稻禾，上面长满了沉甸甸的稻米。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




