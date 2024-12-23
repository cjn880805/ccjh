//shijie4.h

//Sample for room: 终南山石阶4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山石阶4");

	//add npcs into the room
	add_npc("pub_manxiangke");
	add_npc("pub_youke2");

				

	add_door("终南山石阶3", "终南山石阶3", "终南山石阶4");
	add_door("终南山试剑岩", "终南山试剑岩", "终南山石阶4");
	add_door("终南山石阶5", "终南山石阶5", "终南山石阶4");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie5",
                "westdown" : __DIR__"shijie3",
                "southup" : __DIR__"shijianyan",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
