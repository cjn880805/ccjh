//male_shoe.h

//Sample for ITEM 皮靴
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIMaleShoe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "皮靴");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(800);		//set item weight

	set("material", "leather");
	set("unit", "双");
	set("long", "这是一双用上好牛皮作的皮靴。");
	set("value", 500);
	set("apply/dodge", 8);
      	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp