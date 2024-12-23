//tielianzi.h

//Sample for ITEM ������
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CITieLianZi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("unit", "Щ");
	set("value", 1000);
	set("base_unit", "��");
	set("base_weight", 300);
	set("base_value", 1);
	set("material", "iron");
	set("long", "��������һ������ȡʤ�İ��������ߵߵġ�");
	set("wield_msg", "$NѸ�ٵشӰ��������ͳ�һЩ�����ӣ��������оʹ�����!");
	set("unwield_msg","$N������ʣ�µ������Ӿ����Żذ������С�");
    set_amount(80);
// 	init_throwing(5);
 	set("apply/damage",5 );					//set the modifiers of attribute

};



AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



