//jinshe_jian.h

//Sample for ITEM: ���߽�
//coded by Fisho
//data: 2000-11-16

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIjinshe_jian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "���߽�");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(10000);		//set item weight

	set("unit", "��");
	set("long", "�⽣�����ã������������ǳ��أ��������ǻƽ������������������������һ��Ѫ�ۣ����������͵İ��⣬���ǹ��졣������״�������أ�������������һ�����������ɣ���β���ɽ�������ͷ���ǽ��⣬��������ֲ棬���Խ��⾹�����档");
	set("value", 10000);
	set("material", "gold");
	set("wield_msg", "$N��ৡ���һ�����һ��$n�������У���ʱȫ�����쬵�ֻ�к������ˡ�");
	set("unwield_msg", "$N�����е�$n��ؽ��ʡ�");
//	init_sword(150);
	set("apply/damage",150 );					//set the modifiers of attribute

};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp