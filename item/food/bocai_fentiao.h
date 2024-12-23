//bocai_fentiao.h

//Sample for ITEM 菠菜粉条
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbocai_fentiao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "菠菜粉条");	//set item name
	
	set_weight(200);
	
	set("long", "一盆白绿相间，清香可口的菠菜粉条。");
	set("unit", "盆");
	set("value", 150);
	set("food_remaining", 4);
	set("food_supply", 40);
	
};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp