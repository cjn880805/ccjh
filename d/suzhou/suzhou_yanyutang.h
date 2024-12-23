//yanyutang.h

//Sample for room: бргўЬУ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_yanyutang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "бргўЬУ");
	add_npc("pub_lady1");

	add_door("ЫежнЪЈзгСж", "ЫежнЪЈзгСж", "ЫежнбргўЬУ");
	add_door("ЫежнецШЄЭЄ", "ЫежнецШЄЭЄ", "ЫежнбргўЬУ");

	
/*****************************************************
	set("exits", ([
		"west"      : __DIR__"shizilin",
		"southeast" : __DIR__"zhenquting",
	]));
	set("objects", ([
		__DIR__"npc/lady3" : 2,
	]));
********************************************/
};


ROOM_END;
