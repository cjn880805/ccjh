//bowl.h

//Sample for ITEM 海口大碗
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIbowl);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "海口大碗");	//set item name
	
	set_weight(50);
	
	set("unit", "只");
	set("long", "这是一只可盛水的粗瓷大碗。");
	set("value", 0l);
	set("max_liquid", 6);
	set("liquid/type", "water");
	set("liquid/name","清水" );
	set("liquid/remaining",0l );
	set("liquid/drunk_apply", 0l);
	
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp