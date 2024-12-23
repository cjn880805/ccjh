//talin.h

//Sample for room:  天龙寺塔林
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_talin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺塔林");
	add_npc("dali_saodiseng");
				
	add_door("天龙寺大门", "天龙寺大门", "天龙寺塔林");
	add_door("天龙寺舍利塔1", "天龙寺舍利塔1", "天龙寺塔林");
	add_door("天龙寺舍利塔2", "天龙寺舍利塔2", "天龙寺塔林");
	add_door("天龙寺舍利塔3", "天龙寺舍利塔3", "天龙寺塔林");


/******************************************************************************
        set("outdoors", "tianlongsi");
        set("exits", ([
                "south" : __DIR__"ta1",
		"west" : __DIR__"ta3",
		"east" : __DIR__"ta2",
                "north" : __DIR__"damen",
        ]));
	set("objects",([
                __DIR__"npc/saodiseng" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
