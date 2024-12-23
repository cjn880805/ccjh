//shanshen.h

//Sample for ITEM 老山叁
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshanshen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "老山叁");	//set item name

	set("unit", "株");
	set("long", "这是一株沾满山泥的长白老山叁。");
	set("value", 10000);
	set_weight(100);

};
virtual int do_use(CChar * me, CContainer * target)
{
	me->add("eff_hp", 20);
	message_vision("$N吃下一株老山叁，只觉得浑身一股热气兜底冒了上来 !", me);
	destruct(this);
	return 1;

}
/****************

int do_eat(string arg)
{
        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        this_player()->add("eff_qi", 200);
        message_vision("$N吃下一株老山叁，只觉得浑身一股热气兜底冒了上来 !\n", this_player());
        destruct(this_object());
        return 1;
}

*****************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp