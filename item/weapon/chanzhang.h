//chanzhang.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIchanzhang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ����������������ȣ�Լ��ʮ����Ǽ����ֵ��ر�����");
	set("value", 200);
	set("material", "steel");
	set("wield_msg", "$N���һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n������䡣");
	set("shaolin",1);
	set("apply/damage", 25);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp