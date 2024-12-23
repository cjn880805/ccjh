//hehua.h 逍遥任务特殊道具
EQUIP_BEGIN(CIhehua)

virtual void create(int nFlag = 0)		
{
	set_name("荷花", "he hua");
	set("long",	"荷花生于池塘，诗人皆赞其出淤泥而不染。");
	set("unit", "朵");
	set_weight(1000);
	set("value", 1);
};

EQUIP_END;




