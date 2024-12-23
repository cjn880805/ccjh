//duanchang.h

//Sample for ITEM 断肠花
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIduanchang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "断肠花");	//set item name

	set("unit", "朵");
	set("long", "这是一朵断肠花,通体通红,鲜嫩欲滴,美丽异常。");
	set("no_get", "你根本不敢近前.");
};

virtual int do_use(CChar * me, CContainer * target)
{
	if(random(2)==0)
		me->unconcious();
	else 
		me->die();
	destruct(this);

    return 1;
}

/*************************
int do_eat(string arg)
{
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="duanchang") 
	{
		if(random(2)==0) this_player()->unconcious();
		else this_player()->die();
		destruct(this_object());
	}
	return 1;
}

**********************************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp