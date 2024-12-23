//nwhouse.h

//Sample for room: 民房
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_nwhouse);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "民房");

	//add npcs into the room
	add_npc("pub_cuihua");

	add_door("华山村", "华山村", "华山村民房");
   	set("long","这是一个小房间，屋子里飘着一股大葱加香粉的味道。靠墙摆着张大床，床头有个小梳妆台." );
    
/*****************************************************
        set("exits", ([ 
            "northeast" : __DIR__"nwroad2",
        ]));
        set("objects", ([
                __DIR__"npc/cuihua": 1
        ]) );
//        
********************************************/
};


ROOM_END;
