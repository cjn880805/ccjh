//mian.h

//Sample for ITEM 面
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CImian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "面");	//set item name

	set_weight(100);

	set("long", "一碗热气腾腾的汤面。");
	set("unit", "碗");
	set("value", 100);
	set("remaining", 2);
	set("food_supply", 25);
	set("water_supply", 10);

};
virtual int do_use(CChar * me, CContainer * target)
{
    if( me->is_busy() )
	{
		tell_object(me,"你上一个动作还没有完成。");
		return 0;
	}
//  if(   me->query("food")  >= me->max_food_capacity() )
//	{
//		tell_object(me,"你已经吃太饱了，再也吃不下了。");
//		return 1;
//	}
    set("value", 0l);
    me->add("food", query("food_supply"));

//  if( me->query("water") < me->max_water_capacity()-query("water_supply"))
//		me->add("water", query("water_supply"));

    if( me->is_fighting() ) 
		me->start_busy(2);
    add("remaining", -1);
	if ( query("remaining") )
   		 message_vision("$N端起汤面，狼吞虎咽地吃起来。", me);
	else 
	{ 
		message_vision("$N端起碗来，把剩下的面连汤吞了。",me);
		message_vision("$N将碗往后一扔，抹了抹嘴，赞道：好香！",me);
		destruct(this);
	}
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp