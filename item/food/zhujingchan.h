//zhujingchan.h

//Sample for ITEM 朱睛冰蟾
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzhujingchan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "朱睛冰蟾");	//set item name

	set("unit", "只");
	set("value", 4000);
	set("long", "这是一千年难得一见的朱睛冰蟾, 通体透明,惟眼呈赤色, 能解百毒。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。");

	message_vision("$N吃下一只朱睛冰蟾，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！" , me);
	
	if (me->query("condition/drunk"))
		me->apply_condition("drunk",0);

	if (me->query("condition/flower_poison"))
		me->apply_condition("flower_poison",0);
	
	if (me->query("condition/ice_poison"))
		me->apply_condition("ice_poison",0);
	
	if (me->query("condition/iceshock"))
		me->apply_condition("iceshock",0);
	
	if (me->query("condition/rose_poison"))
		me->apply_condition("rose_poison",0);
	
	if (me->query("condition/sanxiao_poison"))
		me->apply_condition("sanxiao_poison",0);
	
	if (me->query("condition/scorpion_poison"))
		me->apply_condition("scorpion_poison",0);
	
	if (me->query("condition/slumber_drug"))
		me->apply_condition("slumber_drug",0);
	
	if (me->query("condition/snake_poison"))
		me->apply_condition("snake_poison",0);
	
	if (me->query("condition/ss_poison"))
		me->apply_condition("ss_poison",0);
	
	if (me->query("condition/xx_poison"))
		me->apply_condition("xx_poison",0);
	
	if (me->query("condition/zhua_poison"))
		me->apply_condition("zhua_poison",0);
		
	if (me->query("condition/wuwen_poison"))
		me->apply_condition("wuwen_poison",0);	
	
	if (me->query("condition/wc_poison"))
		me->apply_condition("wc_poison",0);
	
	if (me->query("condition/dog_poison"))
		me->apply_condition("dog_poison",0);				
	
    destruct(this);
 	me->start_busy(2);
	return 1;
}
/****************************
int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if (me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");
	if(arg=="chan") 
	{
message_vision(HIG"$N吃下一只朱睛冰蟾，只觉一股清香沁入心肺，顿时灵台一片空明，神意清爽！\n" NOR, me);
		if (me->query_condition("drunk"))
			me->apply_condition("drunk",0);
		if (me->query_condition("flower_poison"))
			me->apply_condition("flower_poison",0);
		if (me->query_condition("ice_poison"))
			me->apply_condition("ice_poison",0);
		if (me->query_condition("iceshock"))
			me->apply_condition("iceshock",0);
		if (me->query_condition("rose_poison"))
			me->apply_condition("rose_poison",0);
		if (me->query_condition("sanxiao_poison"))
			me->apply_condition("sanxiao_poison",0);
		if (me->query_condition("scorpion_poison"))
			me->apply_condition("scorpion_poison",0);
		if (me->query_condition("slumber_drug"))
			me->apply_condition("slumber_drug",0);
		if (me->query_condition("snake_poison"))
			me->apply_condition("snake_poison",0);
		if (me->query_condition("ss_poison"))
			me->apply_condition("ss_poison",0);
		if (me->query_condition("xx_poison"))
			me->apply_condition("xx_poison",0);
		if (me->query_condition("zhua_poison"))
			me->apply_condition("zhua_poison",0);
		destruct(this_object());
	}
	me->start_busy(2);
	return 1;
}
*************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp