//xem_sword.h

//Sample for ITEM: �ط罣
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxem_sword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "�ط罣");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N��������, һ��$n�ƿն���, ����$N�����С�\n");
	set("unwield_msg", "$n��$N����һԾ����, Х�����ƿն�ȥ��\n");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp