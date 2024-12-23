//feihuangshi.h

//Sample for ITEM 飞蝗石
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
AUTOCOMBINE_BEGIN(CIFeiHuangShi);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "飞蝗石");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(500);		//set item weight

	set("unit", "把");
	set("long", "仔细挑选的鹅卵石，大小一致，个个都滴溜溜圆。");
//	set("value", 0l);
	set("value", 1000);
//	set("no_drop","这个东西扔/卖不了的，也不能给别人。");
	set("base_unit", "个");
	set("base_weight", 500);
	set("base_value", 1);
	set("damage", 5);	//Here the damage=int_throwing, added by King
	set_amount(80);

	set("apply/damage", 5);					//set the modifiers of attribute
	
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



