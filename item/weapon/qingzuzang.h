//qingzuzang.h

//Sample for ITEM: ������
//coded by wolfman
//data: 2001-7-23

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIqingzuzang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "������");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "staff");			//set the skill applied
	set_weight(5000);		//set item weight

	set("long", "һ���������ɵ��ȡ�");
	set("unit", "��");
	set("material", "bamboo");
	set("wield_msg", "$N���һ��������ץ�����С�");
	set("unwield_msg", "$N�����е������Ȳ�����С�");

	set("apply/damage", 100);					//set the modifiers of attribute

};

EQUIP_END;
