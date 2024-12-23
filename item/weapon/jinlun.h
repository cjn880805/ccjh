//jinlun.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinlun);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "��");
	set("long","����һ����������ķ��֡�" );
	set("value", 1000);
	set("material", "gold");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg","$N�����е�$n�Ż����䡣");
//	init_hammer(200);
	set("apply/damage",200 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp