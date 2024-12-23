//taomujian.h

//Sample for ITEM: ��ľ��
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CItaomujian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ľ��");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "����");			//set the skill applied
	set_weight(1000);		//set item weight

	set("unit", "��");
	set("value", 100);
	set("material", "bamboo");
	set("long", "����һ����ϰ�����õ���ľ����");
	set("wield_msg", "$N�ó�һ�������õ�$n���������С�");
	set("unequip_msg", "$N�������е�$n��");
//	init_sword(10);
 	set("apply/damage", 10);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp