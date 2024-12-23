//zhaohong.h

//Sample for ITEM: ‘Ê∫Ï∂–√Ê∆§≈€
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIzhaohong);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "‘Ê∫Ï∂–√Ê∆§≈€");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(4000);		//set item weight
             
	set("unit", "º˛");
	set("material", "cloth");
	set("value",3000);
	set("apply/armor", 16);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp