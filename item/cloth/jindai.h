//jindai.h

//Sample for ITEM: 束发金带
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIjindai);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "束发金带");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(50);		//set item weight
   
	set("unit", "条");
	set("value", 1500);
	set("material", "silk");
	set("apply/per", 1);
	set("apply/armor", 1);
	set("wear_msg", "$N将$n拿出束在头发上。");

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp