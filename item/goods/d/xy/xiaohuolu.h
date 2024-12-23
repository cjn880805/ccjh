//xiaoshimo.h 逍遥任务特殊道具
ITEM_BEGIN(CIxiaohuolu)

virtual void create(int nFlag = 0)		
{
	set_name("小火炉", "huo lu");
	set("long",	"只见小火炉里的碳被烧得红红的，你准备烧东西吗？");
	set("unit", "个");
	set_weight(1000);
	set("no_get"," ");
};

ITEM_END;




