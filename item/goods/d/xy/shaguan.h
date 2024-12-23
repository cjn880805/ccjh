//shen.h 逍遥任务特殊道具
ITEM_BEGIN(CIshaguan)

virtual void create(int nFlag = 0)		
{
	set_name("砂罐", "sha guan");
	set("long",	"这是寻常人家用来烧菜煮饭用的砂罐。");
	set("unit", "口");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




