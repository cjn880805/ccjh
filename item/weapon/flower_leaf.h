//flower_leaf.h

//Sample for ITEM 花瓣
//coded by Fisho
//data: 2000-10-27

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
AUTOCOMBINE_BEGIN(CIFlowerLeaf);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "花瓣", "huaban");	//set item name

	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "throwing");			//set the skill applied
	set_weight(2);		//set item weight

	set("long", "新鲜的玫瑰花的花瓣，上面还挂这晶莹的露珠。");
	set("unit", "把");
	set("value", 500);
	set("base_unit", "片");
	set("base_weight", 1);
	set("base_value", 1);
	set("apply/per", 20);
	set("damage", 2);	//Here the damage=int_throwing, added by King

	set_amount(80);

	set("apply/damage", 2);					//set the modifiers of attribute
};


AUTOCOMBINE_END;
//last, register the item into ../server/ItemSetup.cpp



