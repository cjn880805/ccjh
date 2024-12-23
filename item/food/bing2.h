//bing2.h

//Sample for ITEM 二举饼
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbing_2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "二举饼");	//set item name

	set("unit", "个");
 	set("long", "这是一个甜香的二举饼。");
	set("value",280000); //add by Fisho
  	
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->add("combat_exp",168);
	me->add("potential",6);
	message_vision( "$N三口两口吃下一块$n。" , me, this );
	destruct(this);
	return 1;
}

virtual void owner_is_killed(CChar * killer)
{
	destruct(this);
}
/*****************

int do_eat(string arg)
{
	object me=this_player();
	if (!id(arg))  return notify_fail("你要吃什么？\n");
	if(arg=="bing2"||arg=="erjubing")
	{
		me->add("combat_exp",168);
		me->add("potential",6);
		message_vision(HIY "$N三口两口吃下一块$n。\n" NOR, this_player(), this_object());
		destruct(this_object());
	}
	return 1;
}
void owner_is_killed()
{
        destruct(this_object());
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp