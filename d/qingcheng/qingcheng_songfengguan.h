//songfengguan.h

//Sample for room: 松风观
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_songfengguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "松风观");

	//add npcs into the room
	add_npc("pub_shentinkang");/////////////////////////

	add_door("青城上清宫", "青城上清宫", "青城松风观");


/*****************************************************
	set("exits", ([
		"north" : __DIR__"shangqing",
	]));
	set("objects", ([
		__DIR__"npc/hai" : 1,
	]));
//	
*****************************************************/
};


ROOM_END;
