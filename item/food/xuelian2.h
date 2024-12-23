//xuelian2.h

//Sample for ITEM 天山雪莲
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxuelian2);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "天山雪莲");	//set item name

	set("unit", "支");
	set("long","这是一支只有在寒冷的地方才能生长的雪莲。.");
	set("value", 100);

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_mp") == me->query("max_mp"))
		return notify_fail("你现在不用吃这宝贝!");
	me->receive_curing("mp",200);
	message_vision("$N小心地吃下一株雪莲,顿时觉得神清气爽了不少!",me);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp