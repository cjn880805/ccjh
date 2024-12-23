//xiang.h

//Sample for ITEM 翔少爷
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxiang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "翔少爷");	//set item name

	set_weight(50);

	set("unit", "粒");
	set("long", "这是一粒助长内力的灵药，吃了之后有要飞翔的欲望，像个少爷似的。");

};

virtual int do_use(CChar * me, CContainer * target)
{
	if ( me->query("mp") >= me->query("max_mp")*2 )
        return notify_fail("你现在没必要吃翔少爷。");
	
	me->add("mp", 1);
	message_vision( "$N吃下一粒翔少爷，只觉得身轻如燕要飞翔！" , me);
	
	destruct(this);
 	return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp