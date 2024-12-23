//sroad7.h

//Sample for room:  血刀门大雪山口7
//coded by zouwenbin
//data: 2000-11-28

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRXueDao_sroad7);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "血刀门大雪山口7");

	add_npc("pub_caiyaoren");

	add_door("血刀门大雪山山谷8", "血刀门大雪山山谷8", "血刀门大雪山口7");
	add_door("血刀门大雪山口6", "血刀门大雪山口6", "血刀门大雪山口7");

    

/******************************************************************************
        set("exits",([
                "eastdown"  : __DIR__"sroad6",
                "southup"   : __DIR__"sroad8",
        ]));
        set("objects",([
                __DIR__"npc/caiyaoren": 1,
        ]));
******************************************************************************/
};


ROOM_END;
