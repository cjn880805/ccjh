//putongbishou.h

//Sample for ITEM: ��ͨذ��
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIputongbishou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ͨذ��");	//set item name
	
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(6000);		//set item weight
	
	set("unit", "��");
	set("long", "����һ����ͨ��Сذ�ס�����������˱ȽϺ��ʡ�");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N�Ӷ����ͳ�һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n�Żᶵ�");
	set("apply/damage", 30);					//set the modifiers of attribute
	
};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp