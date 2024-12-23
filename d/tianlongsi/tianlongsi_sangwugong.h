//sangwugong.h

//Sample for room:  天龙寺三无宫
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_sangwugong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺三无宫");

	add_npc("dali_laoniansengren");
				
	add_door("天龙寺兜率大士院", "天龙寺兜率大士院", "天龙寺三无宫");
	add_door("天龙寺慈悲院", "天龙寺慈悲院", "天龙寺三无宫");

    

/******************************************************************************
        set("exits", ([
                "southeast" : __DIR__"doushuai",
		"north" : __DIR__"cibeiyuan",
	]));
	set("objects",([
                "/d/wudang/npc/guest" : 4,
		__DIR__"npc/laoniansengren" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
