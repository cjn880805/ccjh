//seng_xie.h

//Sample for ITEM ɮЬ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CISengXie);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ɮЬ");	//set item name

	set("wield_position", WIELD_BOOT);		//set the position of wield
	set_weight(1000);		//set item weight

	set("unit", "˫");
	set("long", "һ˫�������õ��಼ɮЬ��");
	set("value", 100);
	set("material", "boots");
	set("apply/dodge", 5);
        	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp