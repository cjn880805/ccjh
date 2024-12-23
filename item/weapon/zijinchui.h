//zijinchui.h

//Sample for ITEM: �Ͻ�
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIzijinchui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�Ͻ�");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(20000);		//set item weight

	set("unit", "ö");
	set("long", "����һö�ɺ��׽�ĸ������ɵĴ󴸣�����ȥ�Ϲ�ӯӯ, �Եü��ǳ��ء�");
	set("value", 3000);
	set("material", "steel");
	set("wield_msg", "$N���һ��, �ճ�һö���ص�$n��");
	set("unwield_msg", "$N�����е�$n�����ջء�");
//	init_hammer(40);
	set("apply/damage", 50);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp