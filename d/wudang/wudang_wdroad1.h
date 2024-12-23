//wdroad1.h

//Sample for room: 青石大道1
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_wdroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青石大道1");
	
//	add_npc("tiezhang_mayi");             //zdd by zdn 2001-07-20


	add_door("武当三不管", "武当三不管", "武当青石大道1");
	add_door("武当松林", "武当松林", "武当青石大道1");


    

/*****************************************************
    set("outdoors", "wudang");
	set("exits", ([
		"south"     : __DIR__"wdroad2",
		"north"     : "/d/city/nanmen",
	]));
*****************************************************/
};


ROOM_END;
