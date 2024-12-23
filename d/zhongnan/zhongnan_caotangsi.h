//caotangsi.h

//Sample for room: 终南山草堂寺
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_caotangsi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山草堂寺");

	add_npc("pub_xiangke");   //2001-07-10 zdn add

	add_door("终南山山路7", "终南山山路7", "终南山草堂寺");

	set("long","这是一座位於终南山北麓的小寺。寺院中的一口古井，名为烟雾井。因为每天清晨都会有一股巨大的烟雾，自井里袅袅升起，不少游客来此，就是为了一观此奇景。往南上是一条崎岖的山道。往北是一条阴森森的小径。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southup"     : __DIR__"shanlu7",
//                "north"       : __DIR__"",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
