//sanbuguan.h

//Sample for room: 武当三不管
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_sanbuguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武当三不管");

	//add npcs into the room
//	add_npc("animal_cow");/////////////////////////
	add_npc("pub_wufa");
	add_npc("pub_wutian");

	add_door("武当青石大道1", "武当青石大道1", "武当三不管");
	add_door("峨嵋小路", "峨嵋小路", "武当三不管");
	add_door("成都东府河桥", "成都东府河桥", "武当三不管");

   	
 
/*****************************************************
        set("outdoors", "wudang");
        set("exits", ([
            "east"      : __DIR__"wdroad8",
            "southeast" : __DIR__"wdroad9",
            "southwest" : "/d/emei/wdroad",
        ]));
        set("objects", ([
		__DIR__"npc/cow": 1,
        ]));
*****************************************************/
};


ROOM_END;
