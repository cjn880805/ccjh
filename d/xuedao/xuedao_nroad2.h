//nroad2.h

//Sample for room:  血刀门山路2
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_nroad2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门山路2");

	add_npc("huashan_shuidai");
				
	add_door("血刀门山路1", "血刀门山路1", "血刀门山路2");
	add_door("血刀门山路4", "血刀门山路4", "血刀门山路2");


/******************************************************************************
        set("exits",([
                "south"     : __DIR__"nroad4",
                "eastdown"  : __DIR__"nroad2",
        ]));
        set("objects",([
                __DIR__"npc/lutianshu" : 1,
                __DIR__"npc/shuidai"   : 1,
                __DIR__"npc/eagle"     : 2,
        ]));
******************************************************************************/
};


ROOM_END;
