//qimeigun.h

//Sample for ITEM ��ü��
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIQiMeiGun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ü��", "qimeigun");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "club");			//set the skill applied
	set_weight(3000);		//set item weight

	set("apply/damage", 25);					//set the modifiers of attribute

	set("unit", "��");
	set("long", "����һ����ľ���������ٿ���ü�����غ��ˣ��ɹ�����Ƭ���ˡ�");
	set("value", 200);
	set("material", "steel");
	set("wield_msg", "$N���һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n������䡣");
	set("shaolin",1);
//	init_club(15);
 	set("apply/damage", 15);					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp