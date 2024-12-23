//tyroad10.h

//Sample for room: 武当桃园小路10
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当桃园小路10");


	add_door("武当桃园小路9", "武当桃园小路9", "武当桃园小路10");
	add_door("武当果园小路1", "武当果园小路1", "武当桃园小路10");

    	

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"gyroad2",
		"west" : __DIR__"tyroad9",
	]));
*****************************************************/
};


ROOM_END;
