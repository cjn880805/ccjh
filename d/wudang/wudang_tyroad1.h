//tyroad1.h

//Sample for room: 武当石阶
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当石阶");
	
	add_npc("tiezhang_gu");             //zdd by zdn 2001-07-20


	add_door("武当广场", "武当广场", "武当石阶");
	add_door("武当桃园小路8", "武当桃园小路8", "武当石阶");

    

/*****************************************************
	set("outdoors", "wudang");
	set("exits", ([
		"westup" : __DIR__"guangchang",
		"east" : __DIR__"tyroad8",
	]));
*****************************************************/
};


ROOM_END;
