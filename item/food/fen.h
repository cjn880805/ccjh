//fen.h

//Sample for ITEM 蛇胆粉
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIfen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "蛇胆粉");	//set item name

	set("unit", "包");
	set("long", "这是疗伤的『蛇胆粉』。");
	set("value", 2000);
 
};

virtual int do_use(CChar * me, CContainer * target)
{
	if (me->query("eff_hp") >= me->query("max_hp"))
		return notify_fail("你现在不需要用金创药。");
	if(random(2)==0)
	{
		message_vision( "$N吃下一包蛇胆粉，觉得象是土豆粉，连呼上当~~~~~" , me);
		destruct(this);
		return 1;
	}
	me->add("hp",30);
	me->add("eff_hp",20);
	message_vision( "$N吃下一包蛇胆粉，顿觉真气上涌，精神好了些。" , me);
	destruct(this);
	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp