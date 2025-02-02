//tiehuwan.h

//Sample for ITEM: 铁护腕
//coded by Fisho
//data: 2000-11-14

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

//npc_name must use "CI-" begin since it belongs item class
EQUIP_BEGIN(CItiehuwan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "铁护腕");	//set item name

	set("wield_position", WIELD_WRIST);		//set the position of wield
 	set_weight(500);		//set item weight
      
	set("unit", "双");
	set("long", "这是一件皮质的护腕，上面满布铁钉，用以保护腕部。");
	set("value", 600);
	set("material", "wrists");
	set("apply/armor", 5);
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp