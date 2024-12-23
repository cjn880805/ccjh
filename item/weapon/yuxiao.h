//yuxiao.h

//Sample for ITEM: ����
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIyuxiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	
	set("skill_type", "sword");
	set("music_type", "xiao");

	set_weight(500);		//set item weight

	set("unit", "֧");
	set("long", "һ֧�������ɵĳ������ȥ��Ө�����������˾�������������������񲢲���ʵ��");
	set("value", 1000);
	set("material", "bamboo");
	set("wield_msg", "$N����һ�ӣ������Ѷ���һ֧��Ө��������");
	set("unwield_msg", "$N��������һת��գ�ۼ�������Ȼ����Ӱ�١�");
//	init_sword();
	set("apply/damage", 20);					//set the modifiers of attribute

};

EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp