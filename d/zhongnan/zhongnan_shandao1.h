//shandao1.h

//Sample for room: 终南山山道1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山道1");
	
	//add npcs into the room  2001-07-10 zdn add 
	add_npc("pub_youke2");

	add_door("终南山山路7", "终南山山路7", "终南山山道1");
	add_door("终南山山道2", "终南山山道2", "终南山山道1");

	set("long","此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，就要掉进万丈深渊了。往东南是一块广大的空地。往北下通往后山脚，远远可以望见一个较大的湖。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southeast"   : __DIR__"shanlu7",
                "northdown"   : __DIR__"shandao2",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
