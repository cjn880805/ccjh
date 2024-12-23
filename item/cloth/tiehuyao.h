//tiehuyao.h

//Sample for ITEM: 铁护腰
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CItiehuyao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁护腰");	//set item name

	set("wield_position", WIELD_WAIST);		//set the position of wield
 	set_weight(500);		//set item weight
      
	set("unit", "条");
	set("long", "这是一件皮质的护腰，上面满布铁钉，用以保护腰部。");
	set("value", 600);
	set("material", "waist");
	set("apply/armor", 5);
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp