//male4_cloth.h

//Sample for ITEM 短打劲装
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIMale4Cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "短打劲装");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(3000);		//set item weight

	set("unit", "件");
	set("long", "一件很利索的短打劲装。");
	set("material", "cloth");
	set("value", 100);
	set("apply/armor", 3);
      	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp