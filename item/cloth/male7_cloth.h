//male7_cloth.h

//Sample for ITEM ���ƽ���
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIMale7Cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ƽ���");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(8000);		//set item weight

	set("unit", "��");
	set("long", "����һ�����ƽ��ۡ�");
	set("material", "cloth");
	set("value", 100);
	set("apply/armor", 2);
      	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp