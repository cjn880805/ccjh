//shanlu7.h

//Sample for room: 终南山山路7
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路7");
	
	//add npcs into the room 2001-07-10 zdn add 
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("终南山大校场", "终南山大校场", "终南山山路7");
	add_door("终南山草堂寺", "终南山草堂寺", "终南山山路7");
	add_door("终南山山道1", "终南山山道1", "终南山山路7");
	add_door("终南山山路6", "终南山山路6", "终南山山路7");

	set("long","这是一条非常崎岖难行的山路，一路蜿蜒盘山ㄦ上，沿途均是葱郁的古柏山林，蔚然森秀。在此处可眺望终南山的景色，只见山险岭峻，山川毓秀，不少鸟ㄦ在枝头高声啼唱不绝。往北下是草堂寺。往西上是一条山路。往东是一块广大的空地。往西北通往后山下。" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "westup"     : __DIR__"shanlu6",
                "northdown"  : __DIR__"caotangsi",
                "northwest"  : __DIR__"shandao1",
                "eastdown"   : __DIR__"daxiaochang",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
