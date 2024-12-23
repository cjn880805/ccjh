//cuipinggu.h

//Sample for room: 终南山翠屏谷
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_cuipinggu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山翠屏谷");
	
	add_npc("pub_man");
	add_npc("pub_daoke");   //2001-07-10  zdn add

	add_door("终南山山路3", "终南山山路3", "终南山翠屏谷");
	add_door("终南山柏树林", "终南山柏树林", "终南山翠屏谷");

    set("long","你的面前是一座形如屏风的大山壁，山壁上郁郁葱葱都是树，一眼看过去，全是一片翠绿色。这就是此地名叫翠屏谷的由来。从这里继续北上，就到了终南山上的柏树林了。" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"shanlu3",
                "northup" : __DIR__"baishulin1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
