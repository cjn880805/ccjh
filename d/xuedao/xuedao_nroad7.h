//nroad7.h

//Sample for room:  血刀门山路7
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad7);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山路7");

	add_npc("xueshan_shanyong");

	add_door("血刀门山路6", "血刀门山路6", "血刀门山路7");
	add_door("血刀门山脚", "血刀门山脚", "血刀门山路7");

	set("long","你走在一山路上，四周有一座座小山丘。");

/******************************************************************************
        set("exits",([
                "eastdown" : "/d/xueshan/shanjiao",
                "south"    : __DIR__"nroad6",
        ]));
        set("objects",([
                CLASS_D("xueshan")+"/shanyong" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
