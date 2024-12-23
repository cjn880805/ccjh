//ta3.h

//Sample for room:  天龙寺舍利塔3
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_ta3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺舍利塔3");

	add_npc("pub_guest");
				
	add_door("天龙寺塔林", "天龙寺塔林", "天龙寺舍利塔3");

	set("long","这是天龙三塔之一，建于唐初，年代久远。传说月圆之夜，在此塔之下默许心愿，塔顶会出现圣光指点迷津，助你达成心愿。");

/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "west" : __DIR__"talin",
        ]));
	set("objects",([
                "/d/wudang/npc/guest" : 2,
        ]));
******************************************************************************/
};


ROOM_END;
