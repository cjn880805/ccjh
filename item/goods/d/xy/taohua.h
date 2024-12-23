//taohua.h 逍遥任务特殊道具
ITEM_BEGIN(CItaohua)

virtual void create(int nFlag = 0)		
{
	set_name("桃花", "tao hua");
	set("long",	"这是一朵绚丽的花。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




