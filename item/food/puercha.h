//puercha.h

//Sample for ITEM 茶壶
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIpuercha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "茶壶");	//set item name

	set_weight(700);
	
	set("long", "一个用来装茶的大茶壶，大概装得八、九杯的茶。\n");
	set("unit", "个");
	set("value", 150);
	set("max_liquid", 15);
	set("liquid/type", "water");
	set("liquid/name","云南普洱茶" );
	set("liquid/remaining", 15);
	set("liquid/drunk_apply", 5);
 	
};


ITEM_END;
//last, register the item into ../server/ItemSetup.cpp