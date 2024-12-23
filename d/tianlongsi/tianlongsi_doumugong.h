//doumugong.h

//Sample for room:  天龙寺斗母宫
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_doumugong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺斗母宫");


	add_npc("pub_guest");
				
	add_door("天龙寺雨花院", "天龙寺雨花院", "天龙寺斗母宫");
	add_door("天龙寺兜率大士院", "天龙寺兜率大士院", "天龙寺斗母宫");

    	

/******************************************************************************
        set("exits", ([
                "southwest" : __DIR__"doushuai",
		"north" : __DIR__"yuhuayuan",
	]));
	set("objects",([
                "/d/wudang/npc/guest" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
