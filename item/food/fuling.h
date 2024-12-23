//fuling.h

//Sample for ITEM 茯苓
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfuling);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("茯苓", "fuling");	//set item name

	set_weight(500);
		
	set("unit", "块");
	set("long", "这是一块成型的茯苓，看来可以入药。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	tell_object(me,"你三口两口把茯苓吃了下去。");
	destruct(this);
	return 1;
}
/******************
int do_eat(string arg)
{
        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="fuling")
        {
                write("你三口两口把茯苓吃了下去。\n");
                destruct(this_object());
        }
        return 1;
}
*********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp