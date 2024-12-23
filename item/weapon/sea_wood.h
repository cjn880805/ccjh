//sea_wood.h

//Sample for ITEM: �Ϻ���ľ
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIsea_wood);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�Ϻ���ľ");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(2000);		//set item weight
       
	set("unit", "��");
	set("long", "����һ�����巢�����Ľ���ľ����");
	set("value", 2000);
	set("material", "wood");
	set("wield_msg", "$N�ӱ����Ϻ���ľ�γ������������С�");
	set("unwield_msg", "$N�����е�$n���²�ر���");
//	init_sword(150);
 	set("apply/damage", 150);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp