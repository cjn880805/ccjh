//yaochu.h 逍遥任务特殊道具
EQUIP_BEGIN(CIyaochu)

virtual void create(int nFlag = 0)		
{
	set_name("药锄", "yao chu");
	set("long",	"这是一个江湖郎中们人手一个的药锄，有了它就可以到深山去挖取药材……");
	set("unit", "个");
	set_weight(1000);
	set("wield_position", WIELD_RIGHT_HAND);
};

EQUIP_END;




