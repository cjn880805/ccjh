//yangxin.h

//Sample for ITEM 养心丸
//coded by Fisho
//data: 2000-11-15

//use macro EQUIP_BEGIN(item_name) to declare equip
//and use macro EQUIP_END end declare
FOOD_BEGIN(CIyangxin);

//under, we will custom our item

virtual void create(int nFlag = 0)		//Call it when the item is created
{
	set_name( "养心丸");	//set item name

	set("unit", "颗");
	set("long", "这是一颗暗红发亮的养心丸。");
	set("value", 10000);

};
virtual int do_use(CChar * me, CContainer * target)
{
    me->receive_healing("hp", 200);

	char msg[255];
	snprintf(msg, 255, "%s吃下一颗养心丸，只觉得体内真力源源滋生，不绝如缕。", me->name());
    MessageVision(me, "chat", msg);
    destruct(this);
    return 1;
}

FOOD_END;
//last, register the item into ../server/ItemSetup.cpp