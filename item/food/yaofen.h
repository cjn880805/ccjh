//yaofen.h

//Sample for ITEM 药粉
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIyaofen);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name("药粉", "yaofen");	//set item name

	set("unit", "包");
	set("long", "这是一包专治内伤的药粉。");
	set("value", 1000);

};
virtual int do_use(CChar * me, CContainer * target)
{
	return notify_fail("只有专练可对付‘化骨绵掌’的武功的人才需要服这种药。");
}
/*************

int do_eat(string arg)
{
	if (!id(arg))
		return notify_fail("你要吃什么药？\n");
	return notify_fail("只有专练可对付‘化骨绵掌’的武功的人才需要服这种药。\n");
}
**********************/
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp