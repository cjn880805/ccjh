//wuming.h

//Sample for ITEM 无名花
//coded by Fisho
//data: 2000-11-13

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
ITEM_BEGIN(CIwuming);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "无名花");	//set item name

	set("unit", "朵");
	set("long", "这是一朵无名小花，花蕊虽小，却十分美丽。");
};

virtual int do_use(CChar * me, CContainer * target)
{
	destruct(this);
	return 1;
}

virtual int Can_Use( )
{
	return 0;
}
ITEM_END;
//last, register the item into ../server/ItemSetup.cpp