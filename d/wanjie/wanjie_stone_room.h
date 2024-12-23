//stone_room.h

//Sample for room: 石屋
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_stone_room);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "石屋");


	add_door("万劫谷小厅", "万劫谷小厅", "万劫谷石屋");
	add_npc("wanjie_foolmaster");

	set("no_fight", 1);


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"backyard",
        ]));
        set("objects", ([ 
            __DIR__"npc/mu" : 1,
        ]));
*****************************************************/
};


ROOM_END;
