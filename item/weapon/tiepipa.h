//tiepipa.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItiepipa);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(50000);		//set item weight

	set("unit", "��");
	set("long", "����һ�����������ã�������൱���ɼ�ʵ��");
	set("value", 3000);
	set("material", "iron");
	set("wield_msg", "$N�ӱ��Ͻ���һ��$n��Ȼ��������С�");
	set("unwield_msg", "$N�������е�$n��");
// 	init_hammer(45);
	set("apply/damage",45 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp