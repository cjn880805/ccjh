//female7_cloth.h

//Sample for ITEM 散花衣
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIFemale7Cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "散花衣");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
 	set_weight(1000);		//set item weight

	set("long", "这件红色的散花衣轻轻爽爽，很是飘逸。");
	set("unit", "件");
	set("value", 100);
	set("material", "cloth");
	set("apply/armor", 1);
	set("apply/per", 3);
	set("female_only", 1);
     	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp