//hedinghong.h

//Sample for ITEM º×¶¥ºì
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIhedinghong);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "º×¶¥ºì");	//set item name

	set("long", "Ò»Æ¿¾ç¶¾µÄ¶¾Ò©, Èç¹ûÓÃÀ´Á¶°µÆ÷ÓÐ¼ûÑª·âºíÖ®Ð§. ");
	set("unit", "Æ¿");
	set("value", 20000);
	
};
virtual int do_use(CChar * me, CContainer * target)
{
	message_vision("$NÑöÍ·¹¾à½¹¾à½¹àÏÂÒ»Æ¿$n", me,this);
	me->die();
	destruct(this);
	return 1;
}
/**************  
int do_eat(string arg)
{
	object me = this_player();

	if(!id(arg))
		return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
	if(arg=="hong" || arg=="heding hong") 
	{
		message_vision("$NÑöÍ·¹¾à½¹¾à½¹àÏÂÒ»Æ¿" + name() + "¡£\n", me);
		me->die();
		destruct(this_object());
	}
	return 1;
}
**********************/

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp