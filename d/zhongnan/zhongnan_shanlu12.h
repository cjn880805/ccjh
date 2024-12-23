//shanlu12.h

//Sample for room: 终南山山路12
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路12");

	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("终南山道路13", "终南山道路13", "终南山山路12");
	add_door("终南山道路11", "终南山道路11", "终南山山路12");

	set("long","这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭峻，山川毓秀，往南下是一条道路。往北上走是一条蜿蜒的山路。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"   : __DIR__"shanlu11",
                "southdown" : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
