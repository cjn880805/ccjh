//shuchang.h

//Sample for room: �鳡
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shuchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�鳡");

	//add npcs into the room
	add_npc("pub_gongzi");/////////////////////////

	add_door("������", "������", "�����鳡");

	set("outdoors", "suzhou");
/*****************************************************
//	
	set("exits", ([
		"south"  : __DIR__"xidajie2",
	]));
	set("objects", ([
		__DIR__"npc/gongzi": 1,
	]));

********************************************/
};


ROOM_END;
