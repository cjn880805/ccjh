//baishulin.h

//Sample for room: 终南山柏树林
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baishulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山柏树林");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("pub_playboy");

	add_door("终南山翠屏谷", "终南山翠屏谷", "终南山柏树林");
	add_door("终南山翠屏峰顶", "终南山翠屏峰顶", "终南山柏树林");

    set("long","绕过翠屏谷的山壁，眼前是一片大柏树林，想是由于山壁挡住了视线，在山下的山路上根本想不到这里的柏树竟会有这么密这么高。你踏进柏树林中，阳光全被头顶的树叶遮住了，越往树林深处，光线越是幽暗。" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"cuipinggu",
                "northup" : __DIR__"baishulin3",
                "east" : __DIR__"baishulin2",
        ]));

********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
