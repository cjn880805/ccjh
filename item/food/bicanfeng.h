//bicanfeng.h

//Sample for ITEM 碧蚕粉
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbicanfeng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "碧蚕粉");	//set item name
	
	set("long", "一袋剧毒的毒药, 如果用来炼暗器有见血封喉之效. ");
	set("unit", "袋");
	set("value", 2000);
  	
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N仰头把一小袋$n都咽了下去。", me,this);
	me->die();
	destruct(this);
	return 1;
}

/***********************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	if(arg=="feng" || arg=="bican feng") 
	{
		message_vision("$N仰头把一小袋" + name() + "都咽了下去。\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
*******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp