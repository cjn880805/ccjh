//rose.h

//Sample for ITEM: 红玫瑰
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIrose);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "红玫瑰");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(1500);		//set item weight
   
	set("unit", "朵");
	set("long","一株盛开的红玫瑰，鲜艳欲滴。花束上一条小小的粉红绶带，上有细细一行小字：欢迎回到你的家。");
	set("value", 2);
	set("material", "plant");
	set("apply/armor", 0l);
	set("apply/per", 3);
	set("wear_msg", "$N轻轻地把一朵$n戴在头上。");
	set("unequip_msg", "$N轻轻地把$n从头上摘了下来。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp