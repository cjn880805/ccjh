//tyroad8.h

//Sample for room: 武当桃园小路8
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_tyroad8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当桃园小路8");

	add_npc("wudang_zhang");
	add_npc("wudang_qingfeng");
	add_npc("wudang_mingyue");

	add_door("武当石阶", "武当石阶", "武当桃园小路8");
	add_door("武当桃园篱笆1", "武当桃园篱笆1", "武当桃园小路8");
	add_door("武当桃园篱笆2", "武当桃园篱笆2", "武当桃园小路8");
	add_door("武当桃园小路9", "武当桃园小路9", "武当桃园小路8");

    	

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
