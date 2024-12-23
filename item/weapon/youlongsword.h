//youlongsword.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyoulongsword);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(8000);		//set item weight

	set("unit", "��");
	set("long","���ǰѿ���������ͨ�ĳ���������ϸһ�����������м���ϸ����˸������");
	set("value", 2400);
	set("material", "blacksteel");
	set("wield_msg", "ֻ������쬡���һ����$N�������Ѿ�����һ�Ѻ�������ı�������$n��");
	set("unequip_msg", "$N�����е�$n��������Ľ��ʡ�");
//	init_sword(100);
	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp