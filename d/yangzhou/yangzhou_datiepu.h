//datiepu.h

//Sample for room: 打铁铺
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "打铁铺");

	//add npcs into the room
	add_npc("pub_tiejiang");
	add_door("扬州城", "扬州城", "扬州打铁铺");

/*****************************************************
	set("exits", ([
		"north" : __DIR__"dongdajie2",
//		"south" : "/d/taohua/dayuan",
	]));
        set("objects", ([
		__DIR__"npc/smith": 1,
	]));
********************************************/
};


ROOM_END;
