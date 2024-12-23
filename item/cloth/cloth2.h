//cloth2.h

//Sample for ITEM: 浅蓝色马褂
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIcloth2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "浅蓝色马褂");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(700);		//set item weight

	set("unit", "件");
	set("value", 100);
	set("material", "cloth");
	
	set("apply/per", 1);
	set("apply/armor", 2);
	set("wear_msg","$N穿上一件$n。");
	set("remove_msg","$将$n脱了下来。");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp