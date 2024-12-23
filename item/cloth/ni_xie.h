//ni_xie.h

//Sample for ITEM 青布尼鞋
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CINiXie);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "青布尼鞋");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(1000);		//set item weight

	set("unit", "双");
	set("long", "一双青布尼鞋。");
	set("value", 200);
	set("material", "boots");
	set("apply/dodge", 5);
	set("female_only", 1);
       	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp