//xxqingxin_san.h

//Sample for ITEM 清心散
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxxqingxin_san);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "清心散");	//set item name

	set("unit", "包");
	set("value", 1000);

};

virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$N吃下一包$n", me,this);

	if (me->query("condition/xx_poison") > 0) 
	{
		me->apply_condition("xx_poison", 0);
	}
	
    destruct(this);
    return 1;
}
/*****************
int do_eat(string arg)
{
   object me = this_player();

   if(!id(arg))
       return notify_fail("你要吃什么？\n");

   message_vision("$N吃下一包" + name() + "。\n", me);
   if (me->query_condition("xx_poison") > 0) {
      me->apply_condition("xx_poison", 0);
   }

   destruct(this_object());
   return 1;
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp