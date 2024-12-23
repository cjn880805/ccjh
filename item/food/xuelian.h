//xuelian.h

//Sample for ITEM 雪莲
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxuelian);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "雪莲");	//set item name

	set("unit", "株");
	set("long","这是一株冰山雪莲.");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
    me->add("eff_hp", 200);
//    me->add("max_hp", 200);

	char msg[255];
	snprintf(msg, 255, "%s服下一株雪莲，顿觉精力百倍", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}
/*****************
int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");
	this_player()->add("eff_qi", 200);
    message_vision("$N服下一株雪莲，顿觉精力百倍!\n", this_player());
	destruct(this_object());
	return 1;
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp