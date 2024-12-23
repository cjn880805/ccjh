//tiedan.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CItiedan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
//	set_weight(1500);		//set item weight

	set("unit", "Щ");
	set("value", 0l);
	set("base_unit", "ö");
	set("base_weight", 4000);
	set("base_value", 1);
	set("no_sell", 1);

	set("material", "iron");
	set("long", "һЩ��Բ����������һ�����͵İ�����");
	set("wield_msg", "$NѸ�ٵش���������һЩ�������������оʹ�������");
	set("unwield_msg","$N������ʣ�µ�����һ���Ͳ����ˡ�");
	set_amount(80);
//	init_throwing(50);
	set("apply/damage",50);					//set the modifiers of attribute

};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



