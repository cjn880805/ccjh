//guiling.h

//Sample for ITEM 龟苓膏
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIguiling);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "龟苓膏");	//set item name

	set_weight(3000);
	
    set("unit", "块");
    set("long", "这是一块用乌龟甲和茯苓配置成的龟苓膏，功能延年益寿。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("max_mp")<=600) 
	{
		tell_object(me,"你吃下了一块龟苓膏，只觉得精神健旺之极，精力直欲奔腾而出。");
		me->add("max_mp",2);
		me->add("mp",2);
	}
	else 
	{
		tell_object(me,"你吃下了一块龟苓膏，但是好象没什么用。");
	}
	destruct(this );
	me->unconcious();
	return 1;
}
/********************

int do_eat(string arg)
{
        object me=this_player();

        if (!(arg))  return notify_fail("你要吃什么？\n");
        if(arg=="gao")
        {
                if (me->query("max_jingli")<=300) {
                        write(YEL"你吃下了一块龟苓膏，只觉得精神健旺之极，精力直
欲奔腾而出。\n"NOR);
                        me->add("max_jingli",20);
                        me->add("jingli",20);
                }
                else {
                        write("你吃下了一块龟苓膏，但是好象没什么用。\n");
                }
                destruct(this_object());
                me->unconcious();
        }
        return 1;
}
***********************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp