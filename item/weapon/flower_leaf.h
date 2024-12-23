//flower_leaf.h

//Sample for ITEM ����
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
AUTOCOMBINE_BEGIN(CIFlowerLeaf);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����", "huaban");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(2);		//set item weight

	set("long", "���ʵ�õ�廨�Ļ��꣬���滹���⾧Ө��¶�顣");
	set("unit", "��");
	set("value", 500);
	set("base_unit", "Ƭ");
	set("base_weight", 1);
	set("base_value", 1);
	set("apply/per", 20);
	set("damage", 2);	//Here the damage=int_throwing, added by King

	set_amount(80);

	set("apply/damage", 2);					//set the modifiers of attribute
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



