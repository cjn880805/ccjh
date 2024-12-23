//dongmen.h

//Sample for room: 苏州东门
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_dongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "苏州东门");

	//add npcs into the room
	add_npc("pub_wujiang");/////////////////////////
	add_npc("pub_bing");

	add_npc("pub_playboy");
	add_npc("pub_tiezhan");

	add_door("苏州中", "苏州中", "苏州东门");
	add_door("泉州山路2", "泉州山路2", "苏州东门");


/*****************************************************
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : "/d/quanzhou/qzroad2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
********************************************/
};


ROOM_END;
