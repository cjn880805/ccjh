//greyrobe.h

//Sample for ITEM 灰色道袍
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIgreyrobe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "灰色道袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1200);		//set item weight

	set("unit", "件");
	set("long", "一件普普通通的灰布道袍。");
	set("material", "cloth");
	set("apply/armor", 2);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp