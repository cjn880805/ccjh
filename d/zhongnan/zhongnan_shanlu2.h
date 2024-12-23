//shanlu2.h

//Sample for room: 终南山山路2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路2");
	
	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("终南山山路3", "终南山山路3", "终南山山路2");
	add_door("终南山山路1", "终南山山路1", "终南山山路2");
	add_door("终南山大官道", "终南山大官道", "终南山山路2");

	set("long","一条山路弯弯曲曲地通向山上。北面的山上好象有一片柏树林，树林中隐隐露出亭子的一角，南面就是上山的路。" );
    

/*****************************************************
        set("exits", ([
                "northeast" : __DIR__"shanlu3",
                "southeast" : __DIR__"shanlu4",
                "westdown" : __DIR__"shanlu1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
