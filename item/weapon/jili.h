//jili.h

//Sample for ITEM ����޼
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CIJiLi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "����޼");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("unit", "Щ");
	set("value", 3500);
	set("base_unit", "ö");
	set("base_weight", 300);
	set("base_value", 1);
	set("material", "iron");
	set("long", "����޼�Ǵ㶾�����������С����������Ĺ⡣");
	set("wield_msg", "$NѸ�ٵش���������һЩ����޼���������оʹ�����!");
	set("unwield_msg","$N������ʣ�µĶ���޼һ���Ͳ����ˡ�");	

    set_amount(80);
	set("apply/damage", 50);					//set the modifiers of attribute

};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp




