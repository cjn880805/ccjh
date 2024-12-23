//seng_cloth.h

//Sample for ITEM �Ҳ�����
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CISengCloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�Ҳ�����");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(5000);		//set item weight

	set("unit", "��");
	set("long", "һ�������˳����ĻҲ����ġ�");
	set("value", 22);
	set("material", "cloth");
	set("apply/armor", 8);
        	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp