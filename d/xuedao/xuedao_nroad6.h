//nroad6.h

//Sample for room:  血刀门山路6
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad6);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山路6");
	add_npc("pub_yunwuxiang");


	add_door("血刀门山路5", "血刀门山路5", "血刀门山路6");
	add_door("血刀门山路7", "血刀门山路7", "血刀门山路6");

	set("long","你走在一山路上，四周有一座座小山丘。远处可以看见终年积雪的山尖。周围的树草已经很难看得到了。");

/******************************************************************************
        set("exits",([
                "north"   : __DIR__"nroad7",
                "southup" : __DIR__"nroad5",
        ]));
        set("objects",([
                __DIR__"npc/huatiegan" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
