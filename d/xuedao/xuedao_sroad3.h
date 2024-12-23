//sroad3.h

//Sample for room:  血刀门雪山路3
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门雪山路3");

	add_npc("pub_luying");
	add_door("血刀门山路1", "血刀门山路1", "血刀门雪山路3");
	add_door("血刀门雪山路2", "血刀门雪山路2", "血刀门雪山路3");
	add_door("血刀门大雪山口4", "血刀门大雪山口4", "血刀门雪山路3");

	set("long","这里是靠近川西的崇山峻岭，怪石嶙峋。再往东去就是川西边缘了。往西有一座雪山高耸入云。路边上有一个大雪坑(hollow)。");
    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad2",
                "northdown"  : __DIR__"nroad1",
                "westup"    : __DIR__"sroad4",
        ]));
        set("objects",([
                __DIR__"npc/liuchengfeng" : 1,
        ]));
        set("item_desc",([
                "hollow"  : "一个雪坑，似乎可以跳(jump)下去。\n"
        ]));
        set("outdoors", "xueshan");
******************************************************************************/
};


ROOM_END;
