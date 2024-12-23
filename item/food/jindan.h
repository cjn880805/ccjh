//jindan.h

//Sample for ITEM 金蛇胆
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIjindan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "金蛇胆");	//set item name
  
	set("unit", "只");
	set("long", "这是一只黄灿灿的金蛇胆，是制备『蛇胆膏』的原料。");
	set("value", 200);


};

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp