//zheshan.h

//Sample for ITEM 油纸折扇
//coded by Fisho
//data: 2000-11-24

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
EQUIP_BEGIN(CIzheshan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "油纸折扇");	//set item name
	
	set("wield_position", WIELD_RIGHT_HAND);		//set the position of wield
	set("skill_type", "sword");			//set the skill applied
	set_weight(12000);		//set item weight
	
	set("unit", "对");
	set("long", "这是一对用镔铁为骨的油纸折扇。");
	set("value", 2000);
	set("material", "steel");
	set("wield_msg", "$N轻描淡写的从袖中掏出一把$n。");
	set("unwield_msg", "$N将手中的$n放入袖中。");
	
	set("apply/damage", 20);					//set the modifiers of attribute
	
};


EQUIP_END;
//last, register the item into ../server/ItemSetup.cpp