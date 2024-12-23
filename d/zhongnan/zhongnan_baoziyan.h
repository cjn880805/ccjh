//baoziyan.h

//Sample for room: 终南山抱子岩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baoziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山抱子岩");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_jianke");
	add_npc("quanzhen_daotong");

	add_door("终南山树林9", "终南山树林9", "终南山抱子岩");
	add_door("终南山树林8", "终南山树林8", "终南山抱子岩");

	set("long","一路过来，山路是越来越险。只见光秃秃的山路，左旁尽是怪石，而右则是万丈深渊，渺不见底。前方不远处的一块巨石，便是有名的抱子岩。再看几眼，觉那岩生得甚是奇怪，就如一个妇人抱着个孩子般，细心呵护。往南和西各是一片密林。" );

/*****************************************************
        set("exits", ([
                "west"      : __DIR__"shulin8",
                "south"     : __DIR__"shulin9",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/chen": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
