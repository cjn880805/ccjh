//male5_cloth.h

//Sample for ITEM 紫蟒袍
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIMale5Cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "紫蟒袍");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(8000);		//set item weight

	set("unit", "件");
	set("long", "一件很重的紫蟒袍。");
	set("material", "cloth");
	set("value", 1000);
	set("apply/armor", 35);
     	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp