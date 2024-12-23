//jitui.h

//Sample for ITEM 烤鸡腿
//coded by Fisho
//data: 2000-11-1

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjitui);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "烤鸡腿");	//set item name

	set_weight(2000);
	
	set("long", "一枝烤得香喷喷的鸡腿。");
	set("unit", "根");
	set("value", 80);
	set("food_remaining", 4);
	set("food_supply", 15);
	set("wield_msg", "$N抓起一根$n，握在手中当武器。");
	set("material", "bone");
	set("unwield_msg", "$N右手一晃，$n已然放回口中。");
 	set("apply/damage", 1);
};
 
virtual int finish_eat()
{
//	if( !query("weapon_prop") ) return 0;
	set_name( "啃得精光的鸡腿骨头");	//set item name
	set_weight(150);
	set("wield_position", WIELD_HAND);		//set the position of wield
	set("long", "一根啃得精光的鸡腿骨头。");

	UpdateMe();
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp



