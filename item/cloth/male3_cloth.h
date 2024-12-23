//male3_cloth.h

//Sample for ITEM ��ɫ��װ
//coded by Fisho
//data: 2000-10-28

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIMale3Cloth);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ɫ��װ");	//set item name

	set("wield_position", WIELD_ARMOR);		//set the position of wield
	set_weight(3000);		//set item weight

	set("unit", "��");
	set("long", "һ���ܱ�ͦ�ĺ�ɫ��װ��");
	set("material", "cloth");
	set("value", 200);
	set("apply/armor", 3);
     	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp