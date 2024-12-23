//baiyunwan.h

//Sample for ITEM 白云熊胆丸
//coded by Fisho
//data: 2000-11-22

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIbaiyunwan);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "白云熊胆丸");	//set item name
	
	set("unit", "颗");
	set("long", "这是一颗武林人士梦寐以求的疗伤圣药。");
	set("value", 3000);
	
};

virtual int do_use(CChar * me, CContainer * target)
{
	me->receive_curing("hp", 100);
	message_vision("$N吃下一颗白云熊胆丸，只觉精气上升，气色大好。", me);
	destruct(this);
	return 1;
}


FOOD_END;
//last, register the item into ../server/ItemSetup.cpp