//shoe.h

//Sample for ITEM: 绣花鞋
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CIshoe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "绣花鞋");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
 	set_weight(300);		//set item weight
           
	set("unit", "只");
	set("long","这是一只漂亮的绣花鞋。");
	set("value", 50);
	set("material", "cloth");
	set("female_only", 1);
	set("apply/armor", 3);

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp