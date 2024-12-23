//hongzao.h 逍遥任务特殊道具
ITEM_BEGIN(CIhongzao)

virtual void create(int nFlag = 0)		
{
	set_name("红枣", "hong zao");
	set("long",	"体红，可作药材、汤料。");
	set("unit", "支");
	set_weight(1000);
	set("value", 180000);
};

ITEM_END;




