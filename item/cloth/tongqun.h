//tongqun.h

//Sample for ITEM Ͳȹ
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItongqun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "Ͳȹ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(20000);		//set item weight

	set("long", "����һ��̨��Ͳȹ��");
	set("material", "cloth");
	set("unit", "��");
	set("value", 200);
	set("apply/armor", 2);
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp