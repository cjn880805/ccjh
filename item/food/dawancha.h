//dawancha.h

//Sample for ITEM 粗磁大碗
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIdawancha);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "粗磁大碗");	//set item name

	set_weight(50);
	
	set("long", "一个蓝边粗磁大碗。");
	set("unit", "个");
	set("value", 0l);
	set("max_liquid", 4);
	set("liquid/type", "tea");
	set("liquid/name", "茶水");
	set("liquid/remaining",4 );
	set("liquid/drunk_supply", 0l);
};

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp