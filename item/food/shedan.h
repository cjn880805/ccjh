//shedan.h

//Sample for ITEM ¸¹Éßµ¨
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIshedan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "¸¹Éßµ¨");	//set item name

	set("unit", "Ã¶");
	set("long", "ÕâÊÇÒ»Ã¶»ðºìµÄ¸¹Éßµ¨¡£");
	set("value", 500);
	
};
virtual int do_use(CChar * me, CContainer * target)
{
	me->unconcious();
	return 1;

}
/***************

int do_eat(string arg)
{
if (!id(arg))  return notify_fail("ÄãÒª³ÔÊ²Ã´£¿\n");
if(arg=="dan") this_player()->unconcious();
}
***********/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp