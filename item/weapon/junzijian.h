//junzijian.h

//Sample for ITEM: ���ӽ�
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjunzijian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���ӽ�");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(7000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ�ڱ���ͨ�ڵĽ����������ý�˿���ż����֣�ǫǫ���ӣ���������");
	set("value", 1200);
	set("material", "steel");
	set("apply/per", 24);
	set("wield_msg", "$N��̾һ������$n����������ʡ�");
	set("unwield_msg", "$N����һ�Σ�$n��Ȼ���ʡ�");
	set("apply/damage", 35);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp