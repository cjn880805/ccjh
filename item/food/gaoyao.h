//gaoyao.h

//Sample for ITEM 狗皮膏药
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIgaoyao);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "狗皮膏药");	//set item name

	set("unit", "帖");
	set("long", "这是一帖武林人士常贴(tie)的狗皮膏药。");
	set("value", 2000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("现在你没空贴狗皮膏药了。");
	if (me->query("eff_hp") == me->query("max_hp"))
		return notify_fail("你现在不需要用狗皮膏药。");
	else
	{
		me->receive_curing("hp", 50);
		message_vision("$N啪的一声在伤口上贴了一帖狗皮膏药，气色看起来好多了。", me);
		me->start_busy(2);
		destruct(this);
		return 1;
	}
	
}

virtual int Can_Use()
{
	return 1;
}

ITEM_END;
//last, register the item into ../server/ItemSetup.cpp