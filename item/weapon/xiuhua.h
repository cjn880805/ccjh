//xiuhua.h

//Sample for ITEM: �廨��
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxiuhua);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("�廨��", "zhen");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(5);		//set item weight

	set("unit", "��");
	set("long", "����һ������ϸĥ���廨�룬���廨�õľ��ѹ��ߡ�");
	set("value", 100);
	set("material", "steel");
	set("wield_msg", "$N��Ĵָ��ʳָ���޼����һ��$n��");
	set("unwield_msg", "$N�����е�$n����޼䡣");
//	init_sword(10);
 	set("apply/damage", 5);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp