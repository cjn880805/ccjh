//tyroad8.h

//Sample for room: �䵱��԰С·8
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�䵱��԰С·8");

	add_npc("wudang_zhang");
	add_npc("wudang_qingfeng");
	add_npc("wudang_mingyue");

	add_door("�䵱ʯ��", "�䵱ʯ��", "�䵱��԰С·8");
	add_door("�䵱��԰���1", "�䵱��԰���1", "�䵱��԰С·8");
	add_door("�䵱��԰���2", "�䵱��԰���2", "�䵱��԰С·8");
	add_door("�䵱��԰С·9", "�䵱��԰С·9", "�䵱��԰С·8");

    	

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : __DIR__"tyroad1",
		"east" : __DIR__"tyroad9",
		"north" : __DIR__"tynroad",
		"south" : __DIR__"tysroad",
	]));
*****************************************************/
};


ROOM_END;
