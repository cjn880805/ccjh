//doujiang.h

//Sample for ITEM 豆浆
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIdoujiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "豆浆");	//set item name

	set_weight(50);

	set("long", "一杯热气腾腾的豆浆～～～");
	set("unit", "杯");
	set("value", 500);
	set("remaining", 2);
	set("drink_supply", 30);
 
};

virtual int do_use(CChar * me, CContainer * target)
{
//   if(me->query("water")  >= me->max_water_capacity() )
//		return notify_fail("你已经喝太多了，再也灌不下一滴水了。");
	
	set("value", 0l);
    me->add("water", query("drink_supply"));
    destruct(this);
	return 1;
}

/****************

int do_drink(string arg)
{
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("你上一个动作还没有完成。\n");
    if(   this_player()->query("water")
       >= this_player()->max_water_capacity() )
     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");

	set("value", 0l);
    this_player()->add("water", query("drink_supply"));
    destruct(this_object());
   return 1;
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp