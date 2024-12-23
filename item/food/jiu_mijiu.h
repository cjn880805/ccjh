//jiu_mijiu.h 米酒

FOOD_BEGIN(CIjiu_mijiu);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "米酒");	//set item name

	set_weight(700);

	set("long", "一瓶上好的米酒。");
	set("unit", "坛");
	set("value", 200000);
};


virtual int Can_Use()
{
	return 1;
}

virtual int do_use(CChar * me, CContainer * target)
{
	if (target != me)
		return notify_fail("酒只能自己喝。");
	
	message_vision( "$N咕嘟咕嘟的把酒喝下。\n$N的脸色一阵红一阵白，好象是喝醉了！",me);
	me->apply_condition("drunk", 10 + random(10));
	me->FlushMyInfo();
	
	destruct(this);
	
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp