//shitou.h

//Sample for ITEM: ��ʯͷ
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIshitou);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��ʯͷ");	//set item name

	set("wield_position", WIELD_HAND);		//set the position of wield
	set("skill_type", "hammer");			//set the skill applied
	set_weight(5000);		//set item weight

	set("unit", "��");
	set("long", "����һƽƽ�����Ĵ�ʯͷ��");
	set("value", 0l);
	set("material", "stone");
	set("wield_msg", "$N����һ��$n׼��ս����");
	set("unwield_msg", "$N�������е�$n��");
//	init_hammer(1);
	set("apply/damage",1 );					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp