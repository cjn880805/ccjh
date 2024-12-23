//jinhua.h

//Sample for ITEM: ������
//coded by cat
//data: 2001-3-19

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinhua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("long", "һ������������С����������ʮ�־��¡�");
	set("unit", "��");
	set("value", 0l);
	set("base_unit", "ö");
	set("base_weight", 10);
	set("base_value", 0l);
	set("damage", 50);
	set_amount(15);
//	init_throwing(50);
	set("apply/damage", 80);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp