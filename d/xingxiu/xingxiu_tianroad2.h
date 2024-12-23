//tianroad2.h

//Sample for room: 星宿海天山山路2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海天山山路2");

	//add npcs into the room
	add_npc("xingxiu_gushou");/////////////////////////
	add_npc("xingxiu_haoshou");
	add_npc("xingxiu_boshou");

				

	add_door("星宿海", "星宿海", "星宿海天山山路2");
	add_door("星宿海天山山路1", "星宿海天山山路1", "星宿海天山山路2");
	add_door("星宿海天山山路3", "星宿海天山山路3", "星宿海天山山路2");


/*****************************************************
        set("exits", ([
            "northup" : "/d/lingjiu/shanjiao",
            "northdown" : __DIR__"xxh1",
            "south" : __DIR__"tianroad1",
        ]));
        set("objects", ([
                "/kungfu/class/xingxiu/shihou" : 1,
                __DIR__"npc/gushou"  : 1,
                __DIR__"npc/haoshou" : 1,
                __DIR__"npc/boshou" : 1,
        ]));
********************************************/
};


ROOM_END;
