//hu.h

//Sample for ITEM 马奶酒壶
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIhu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "马奶酒壶");	//set item name

	set_weight(700);
	
	set("long", "一个用来装马奶酒的大酒壶，大概装得八、九升的酒。");
	set("unit", "只");
	set("value", 100);
	set("max_liquid", 15);
	set("liquid/type", "alcohol");
	set("liquid/name", "马奶酒");
	set("liquid/remaining",15 );
	set("liquid/drunk_supply", 6);

};
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp