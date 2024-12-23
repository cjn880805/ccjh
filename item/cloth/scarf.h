//scarf.h

//Sample for ITEM: 一字逍遥巾
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIscarf);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "一字逍遥巾");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(1000);		//set item weight
           
	set("unit", "条");
	set("value", 300);
	set("material", "cloth");
	set("armor_type", "head");
	set("apply/per", 1);
	set("apply/armor", 4);
	set("apply/dodge", -1);
	set("wear_msg","$N戴上一条$n。");
	set("remove_msg","$N将$n解了下来。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp