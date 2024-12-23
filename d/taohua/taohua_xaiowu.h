//xaiowu.h

//Sample for room: 小屋
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_xaiowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小屋");

	//add npcs into the room
	add_npc("pub_puren");/////////////////////////
	

	add_door("桃花山庄小院", "桃花山庄小院", "桃花岛小屋");

    set("sleep_room","1") ;

/*****************************************************
    set("exits", ([
        "east"  : __DIR__"houyuan",
    ]));
    set("objects", ([
        __DIR__"npc/puren" : 3,
    ]) );    

    set_light(0) ;
//    
********************************************/
};


ROOM_END;
