//huashi.h

//Sample for room:  Ã·×¯»­ÊÒ
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_huashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ã·×¯»­ÊÒ");

	add_door("Ã·×¯×ßÀÈ1", "Ã·×¯×ßÀÈ1", "Ã·×¯»­ÊÒ");
	

    

/******************************************************************************
        set("exits", ([  
            "west" : __DIR__"zoulang1",
        ]));
        set("objects", ([  
            __DIR__"npc/danqing-sheng.c" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
