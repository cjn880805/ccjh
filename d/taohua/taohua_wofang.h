//wofang.h

//Sample for room: 卧房
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_wofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "卧房");

	//add npcs into the room
	add_npc("taohuadao_binu");
	add_npc("taohua_rong");

	add_door("桃花岛山庄正厅", "桃花岛山庄正厅", "桃花岛卧房");
	add_door("桃花山庄书房", "桃花山庄书房", "桃花岛卧房");


	set("sleep_room", 1);
/*****************************************************
    set("exits", ([
        "east" :__DIR__"dating",
    ]));
    set("objects", ([
        CLASS_D("taohua")+"/rong" : 1,
        __DIR__"npc/binu" : 2,
    ]) );
********************************************/
};


ROOM_END;
