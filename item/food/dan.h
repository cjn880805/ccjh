//dan.h

//Sample for ITEM 仙丹
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIdan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "仙丹");	//set item name

	set_weight(20);
	
	set("no_get", "嘿嘿，做梦吧! ");
	set("no_drop","这么宝贵的仙丹，哪能乱扔! ");
	set("unit", "枚");
	set("long","这是一枚仙丹，看上去就像一只小小的金葫芦。");
	set("value", 100000);

};

virtual int do_use(CChar * me, CContainer * target)
{
//	me->set("water", me->max_water_capacity());
//	me->set("food", me->max_food_capacity());
	message_vision("$N吃下一粒仙丹，只觉得精神健旺，气血充盈，好爽，太爽了! ", me);
	destruct(this);
	return 1;
}

/*****************

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
                return notify_fail("你要吃什么？\n");
        me->set("water", me->max_water_capacity());
        me->set("food", me->max_food_capacity());
        message_vision(HIG
 "$N吃下一粒仙丹，只觉得精神健旺，气血充盈，好爽，太爽了! \n"NOR, me);

        destruct(this_object());
        return 1;
}
**********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp