//dadao.h

//Sample for ITEM: ��
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIdadao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "ն��");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "blade");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ�����λεĳ�����");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ���ӱ��󲦳�һ��$n��");
	set("unwield_msg", "$N�����е�$n��ر���");
	set("apply/damage", 40);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp