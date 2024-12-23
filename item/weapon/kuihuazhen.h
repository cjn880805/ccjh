//kuihuazhen.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIkuihuazhen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(1500);		//set item weight

	set("long", "��������һ��ר�Ŵ��Ƶİ��������μ�����ɱ����ǿ.");
	set("unit", "��");
	set("value", 2000);
	set("base_unit", "��");
	set("base_weight", 1);
	set("base_value", 1);
	set("value", 30);
	set_amount(80);
//	init_throwing(20);
	set("apply/damage", 20);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp



