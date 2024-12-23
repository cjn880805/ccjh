//xiao.h

//Sample for ITEM: ������
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIxiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������", "xiao");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	
	set("skill_type", "music");
	set("music_type", "xiao");

	set_weight(4000);		//set item weight

	set("unit", "��");
	set("long", "����һ�����������ɵĶ��");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N��ৡ���һ���ӻ����ͳ�һ��$n�������С�");
	set("unwield_msg", "$N�����е�$n���ػ��");
//	init_dagger(70);
	set("apply/damage", 35);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp