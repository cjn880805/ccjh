//tea_leaf.h

//Sample for ITEM ��Ҷ
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare

AUTOCOMBINE_BEGIN(CITeaLeaf);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "��Ҷ");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied

	set("long", "�Ųɵ��²裬����һ�ɵ�����������");
	set("unit", "��");
	set("value", 400);
	set("base_unit", "Ƭ");
	set("base_weight", 1);
	set("base_value", 1);
	set("damage", 1);	//Here the damage=int_throwing, added by King
	set("material", "wood");
	set("wield_msg", "$NѸ�ٵشӰ��������ͳ�һЩ��Ҷ���������оʹ�������");
	set("unwield_msg","$N������ʣ�µĲ�Ҷ�����Żذ������С�");

	set_amount(80);
	set("apply/damage", 1);					//set the modifiers of attribute
	
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



