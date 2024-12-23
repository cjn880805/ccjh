//jidan.h 逍遥任务特殊道具
ITEM_BEGIN(CIjidan)

virtual void create(int nFlag = 0)		
{
	set_name("鸡蛋", "ji dan");
	set("long",	"鸡下的蛋就叫鸡蛋。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
	call_out(do_die, 850);	
};

static void do_die(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
}

ITEM_END;




