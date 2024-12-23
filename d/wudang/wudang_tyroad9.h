//tyroad9.h

//Sample for room: 武当桃园小路9
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当桃园小路9");


	add_door("武当桃园小路8", "武当桃园小路8", "武当桃园小路9");
	add_door("武当桃园小路10", "武当桃园小路10", "武当桃园小路9");

   	

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"tyroad10",
		"west" : __DIR__"tyroad8",
	]));
*****************************************************/
};


ROOM_END;
