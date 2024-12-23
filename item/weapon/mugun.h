//mugun.h

//Sample for ITEM ľ��
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CImugun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ľ��");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "��");
	set("long", "����һ��ľ������ľ�����ֹ��൱��ϸ��");
	set("value", 50);
	set("material", "steel");
	set("wield_msg", "$N����������һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��������ϡ�");
//  init_staff(5);
	set("apply/damage",5 );					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp