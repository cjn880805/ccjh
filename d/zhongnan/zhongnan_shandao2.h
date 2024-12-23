//shandao2.h

//Sample for room: 终南山山道2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shandao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山道2");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("pub_liumangtou");

	add_door("终南山山道1", "终南山山道1", "终南山山道2");
	add_door("终南山树林10", "终南山树林10", "终南山山道2");

	set("long","此段山路是沿着峭壁而开凿出来的，特别崎岖难行。有时峭壁边必须面贴山璧，侧身而过。尤其当山凤吹来时，更需特别小心，不然一失足，就要掉进万丈深渊了。往东南是一块广大的空地。往北下通往后山脚，远远可以望见一个较大的湖。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shandao1",
                "northdown" : __DIR__"shulin10",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
