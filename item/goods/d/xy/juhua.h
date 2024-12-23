//juhua.h 逍遥任务特殊道具
ITEM_BEGIN(CIjuhua)

virtual void create(int nFlag = 0)		
{
	set_name("菊花", "ju hua");
	set("long",	"梅兰菊竹之老三，其品种甚繁，姿态万千。");
	set("unit", "支");
	set_weight(1000);
	set("value", 1);
};

ITEM_END;




