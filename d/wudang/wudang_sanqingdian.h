//sanqingdian.h

//Sample for room: 三清殿
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWuDang_sanqingdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "三清殿");

	add_npc("wudang_guxu");
	add_npc("wudang_song");
	add_npc("wudang_xi");
	add_npc("pub_xiangke");
	
	add_door("武当广场", "武当广场", "武当三清殿");

    set("valid_startroom", 1);

/*****************************************************
        set("exits", ([
                "north" : __DIR__"guangchang",
                "south" : __DIR__"houyuan",
                "east"  : __DIR__"donglang1",
                "west"  : __DIR__"xilang",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/guxu" : 1,
                CLASS_D("wudang") + "/song" : 1
        ]));
//        
*****************************************************/
};


ROOM_END;




