//kongquedan.h

//Sample for ITEM 孔雀胆
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIkongquedan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "孔雀胆");	//set item name

	set("long", "一瓶剧毒的毒药, 如果用来炼暗器有见血封喉之效. ");
	set("unit", "粒");
	set("value", 20000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N仰头张口吞下一粒%n", me,this);
	me->die();
	destruct(this );
	return 1;
}
/**********************
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("你要吃什么？\n");
	if(arg=="hong" || arg=="heding hong") 
	{
		message_vision("$N仰头张口吞下一粒" + name() + "。\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
*****************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp