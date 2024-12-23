//riyueyan.h

//Sample for room: 终南山日月岩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_riyueyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山日月岩");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("quanzhen_daotong");

	add_door("终南山山路10", "终南山山路10", "终南山日月岩");
	add_door("终南山山道9", "终南山山道9", "终南山日月岩");

	set("long","一路过来，只见光秃秃的山路两旁，怪石林立，颇为吓人。尤其是前方不远处的两块巨石，左边的一块像月亮，右边的那块像太阳，夹道而立，便如一对门神，只留当中一条宽约一人多的小道，让人通过。往东下和北上走都是一条蜿蜒的山路。" );

/*****************************************************
        set("exits", ([
                "eastdown"  : __DIR__"shanlu10",
                "northup"   : __DIR__"shanlu9",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
