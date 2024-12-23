//baihe.h

//Sample for ITEM �׺ϻ�
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIbaihe);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�׺ϻ�");	//set item name

	set_weight(10);
	
	set("unit", "��");
	set("long", "����һ��������СҰ�����������¡�");
	set("value", 0l);
	set("material", "plant");
	set("apply/armor", 0l);
	set("apply/per", 3);
	set("wear_msg", "$N����ذ�һ��$n����ͷ�ϡ�");
	set("unequip_msg", "$N����ذ�$n��ͷ��ժ��������");
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp