//smithy.h

//Sample for room: 铁匠铺
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_smithy);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "铁匠铺");

	//add npcs into the room
	add_npc("pub_tiejiang");

	add_door("华山村", "华山村", "华山村铁匠铺");

/*****************************************************
        set("exits", ([ 
            "east" : __DIR__"smithy2",
            "north" : __DIR__"eroad3",
        ]));
//        
        set("objects", ([
             __DIR__"npc/smith": 1
        ]) );
********************************************/
};


ROOM_END;
