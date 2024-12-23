//muyuchui.h

//Sample for ITEM: ľ���
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImuyuchui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ľ���");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "��");
	set("value", 50);
	set("material", "wood");
	set("long", "����һ�Ѻ������ľ���õ�Сľ鳡�");
	set("wield_msg", "$N���´����ͳ�һ��$n���������е�������");
	set("unequip_msg", "$N�����е�$n�Ż��´���");
	set("shaolin",1);
//	init_hammer(1);
	set("apply/damage", 1);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp