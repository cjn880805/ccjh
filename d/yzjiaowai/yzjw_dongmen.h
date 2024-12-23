//dongmen.h

//Sample for room:  扬州东门
//coded by zwb
//data: 2000-11-22


ROOM_BEGIN(CRYZJW_dongmen);


virtual void create()			//Call it when Room Create
{
	set_name( "扬州东门");

	add_npc("pub_wujiang");
	add_npc("pub_bing");
	add_npc("pub_dongyuyu");

	add_door("扬州东南","扬州东南","扬州东门");
	add_door("扬州东驿道","扬州东驿道","扬州东门");
	add_door("扬州草地1","扬州草地1","扬州东门");


/********************************************************
        set("outdoors", "city");
//	
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : "/d/taishan/yidao",
		"north" : __DIR__"ml1",
		"south" : __DIR__"jiaowai1",
		"west" : __DIR__"dongdajie2",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
*******************************************************/
 
};


ROOM_END;
