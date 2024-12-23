//cuiyu.h

//Sample for ITEM: 翠羽
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIcuiyu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "翠羽");	//set item name

	set("wield_position", WIELD_HEAD);		//set the position of wield
 	set_weight(3000);		//set item weight

	set("unit", "支");
	set("long", "一支翠绿的羽毛。");
	set("value", 800);
	set("material", "plant");
	set("apply/armor", 10);
	set("apply/per", 3);
	set("wear_msg", "$N轻轻地把一朵$n戴在头上。");
	set("unequip_msg", "$N轻轻地把$n从头上摘了下来。");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp