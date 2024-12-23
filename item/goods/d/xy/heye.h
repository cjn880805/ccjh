//heye.h 逍遥任务特殊道具
EQUIP_BEGIN(CIheye)

virtual void create(int nFlag = 0)		
{
	set_name("荷叶", "he ye");
	set("long",	"荷花之叶，呈扇形，坊间以其包饭成粽，更有诗人留下‘绿荷包饭趁墟入’之句。");
	set("unit", "片");
	set_weight(1000);
	set("value", 1);
};

EQUIP_END;




