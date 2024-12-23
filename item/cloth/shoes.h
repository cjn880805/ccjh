//shoes.h

//Sample for ITEM: �廨Ь
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshoes);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("�廨Ь", "shoes");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(1000);		//set item weight
           
	set("unit", "˫");
	set("value", 100);
	set("material", "cloth");
	set("armor_type", "feet");
	set("apply/per", 1);
	set("apply/armor", 2);
	set("apply/dodge", 2);
	set("female_only", 1);
	set("wear_msg","$N����һ˫$n��");
	set("remove_msg","$N��$n����������");
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp