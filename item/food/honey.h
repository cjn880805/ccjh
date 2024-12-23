//honey_san.h

//Sample for ITEM 玉蜂浆
//coded by Cat
//data: 2001-4-3

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhoney);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "玉蜂浆");	//set item name
	set("long", "采集玉蜂皇浆提炼而成，香甜可口。");
	set("unit", "瓶");
	set("value", 2000);
	set_weight(30000);
};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N喝下一瓶$n", me,this);

	if (me->query("condition/yufeng_poison") > 0) 
	{
		me->apply_condition("yufeng_poison", 0);
		message_vision("$N觉一阵清香沁入心肺，身上的玉蜂毒已在不经意间消褪。", me);
	}
	else
		message_vision("$N觉一阵清香沁入心肺，气色好了不少。", me);

	me->receive_healing("hp", 50);
	me->FlushMyInfo();
	destruct(this);
    return 1;
}
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp