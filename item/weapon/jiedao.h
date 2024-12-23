//jiedao.h

//Sample for ITEM: �䵶
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjiedao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�䵶");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(4000);		//set item weight

	set("unit", "��");
	set("value", 500);
	set("material", "iron");
	set("long", "����һ���߰볤�Ľ䵶���������������ֳ��أ����Ǿ�����ɡ�");
	set("wield_msg", "$N���һ�����λε�$n�������С�");
	set("unequip_msg", "$N�����е�$n��������ĵ��ʡ�");
	set("shaolin",1);
//	init_blade(25);
	set("apply/damage",25 );					//set the modifiers of attribute


};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp