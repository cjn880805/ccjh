//gytoad1.h

//Sample for room: �䵱��԰С·1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_gytoad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��԰С·1");


	add_door("�䵱��԰С·10", "�䵱��԰С·10", "�䵱��԰С·1");
	add_door("�䵱��԰С·2", "�䵱��԰С·2", "�䵱��԰С·1");


/*****************************************************
	set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"tyroad10",
		"east" : __DIR__"gyroad2",
	]));
	set("objects", ([
		__DIR__"npc/snake": 1
	]));
*****************************************************/
};


ROOM_END;
