//zaisheng.h

//Sample for ITEM 再生丸
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIzaisheng);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "再生丸");	//set item name

	set("unit", "颗");
	set("long", "这是一颗洁白如玉的再生丸。");
	set("value", 2000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	if ((me->query("potential") - 100) >=  me->query("learned_points") )
		return notify_fail("你现在不需要用再生丸。");
	else
	{
		me->add("potential", 1);
		char msg[255];
		snprintf(msg, 255, "%s吃下一颗再生丸，感到身体里产生了一种微妙的变化", me->name());
		MessageVision(me, "chat", msg);
		destruct(this);
		return 1;
	}
}

/**************************
	if ((this_player()->query("potential") - 100) >=
	     this_player()->query("learned_points") )
		return notify_fail("你现在不需要用再生丸。\n");
	else {
	        this_player()->add("potential", 1);
	        message_vision("$N吃下一颗再生丸，感到身体里产生了一种微妙的变化 !\n", this_player());
	        destruct(this_object());
	        return 1;
	}
}
***********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp