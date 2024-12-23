//jinchuang.h

FOOD_BEGIN(CIjinchuang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("金创药", "jinchuang yao");
	set("unit", "包");
	set("long", "这是一包武林人士必备的金创药。");
	set("value", 2000);	
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。");

	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("你现在不需要用金创药。");
	
	me->receive_curing("hp", 50);
	message_vision("$N吃下一包金创药，气色看起来好多了。", me);
	me->start_busy(2);
	destruct(this);
	
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp