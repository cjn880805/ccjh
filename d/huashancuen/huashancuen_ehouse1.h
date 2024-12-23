//ehouse1.h

//Sample for room: 民宅
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_ehouse1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "民宅");

	//add npcs into the room
	add_npc("pub_poorman");

	add_door("华山村", "华山村", "华山村民宅");

  	set("long","这是一间十分简陋，四壁漏风的小房子，屋子里连一张象样的床都没有，只有一面门板上面铺着些干草。这屋子的主人一定是贫困潦倒，穷的叮当响。" );

/*****************************************************
        set("exits", ([ 
            "south" :__DIR__"wexit",
        ]));
//        
        set("objects", ([
            __DIR__"npc/poorman": 1
        ]) );
*****************************************************/
};


ROOM_END;
