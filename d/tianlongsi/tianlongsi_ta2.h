//ta2.h

//Sample for room:  天龙寺舍利塔2
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_ta2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天龙寺舍利塔2");

				
	add_door("天龙寺塔林", "天龙寺塔林", "天龙寺舍利塔2");


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
