//xionghuang.h

//Sample for ITEM 雄黄
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIxionghuang);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "雄黄");	//set item name

	set("unit", "包");
	set("long", "这是一包雄黄,据说可驱百毒。");
	set("value", 1000);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	return notify_fail("想死啊？雄黄不能吃.");
}
/***********
int do_eat(string arg)
{
	return notify_fail("想死啊？雄黄不能吃.\n");
}
******************/
FOOD_END;
//last, register the item into ../server/ItemSetup.cpp