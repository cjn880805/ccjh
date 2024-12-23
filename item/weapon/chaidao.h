//chaidao.h

//Sample for ITEM: ��
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIchaidao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��");	//set item name
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(1000);		//set item weight
	
	set("unit", "��");
	set("value", 0l);
	set("material", "iron");
	set("long", "����һ�����²��ɵĲ񵶡�");
	set("wield_msg", "$N���һ��$n�������С�");
	set("unequip_msg", "$N�����е�$n������䡣");
	set("apply/damage", 5);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp