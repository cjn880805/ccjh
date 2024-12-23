//shuzhi2.h

//Sample for ITEM: С��֦
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshuzhi2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "С��֦");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(200);		//set item weight
	
	set("unit", "��");
	set("long", "����һ��С��֦��");
	set("value", 10);
	set("material", "wood");
	set("wield_msg", "$N�ó�һ��$n���������С�");
	set("unwield_msg", "$N�������е�$n��");
	set("apply/damage", 1);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp