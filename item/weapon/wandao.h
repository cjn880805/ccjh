//wandao.h

//Sample for ITEM: �������䵶
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIwandao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�������䵶");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ�����λεİ������䵶�����������״�����ж���������ı��С�");
	set("value", 1500);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n��ص��ʡ�");
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp