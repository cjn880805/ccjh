//baihe.h

//Sample for ITEM 白合花
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIbaihe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "白合花");	//set item name

	set_weight(10);
	
	set("unit", "朵");
	set("long", "这是一朵美丽的小野花，香气清新。");
	set("value", 0l);
	set("material", "plant");
	set("apply/armor", 0l);
	set("apply/per", 3);
	set("wear_msg", "$N轻轻地把一朵$n戴在头上。");
	set("unequip_msg", "$N轻轻地把$n从头上摘了下来。");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp