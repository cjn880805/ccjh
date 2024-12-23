//xiongdan.h

//Sample for ITEM 熊胆
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiongdan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "熊胆");	//set item name

	set_weight(1000);

	set("unit", "颗");
	set("long", "这是一颗鲜红的熊胆，看来可以入药。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	tell_object(me, "你三口两口把熊胆吃了下去。");
    destruct(this);
    return 1;
}
/********************
int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="xiongdan")
        {
                write("你三口两口把熊胆吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}
****************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp