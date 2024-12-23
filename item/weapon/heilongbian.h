//heilongbian.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIheilongbian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "whip");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ��ī�ڳ��ޣ������ޱȡ�");
	set("value", 1000);
	set("material", "leather");
	set("wield_msg", "$N��ৡ���һ������һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n������䡣");
//	init_whip(25);
	set("apply/damage", 45);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp