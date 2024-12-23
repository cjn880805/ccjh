//chufang.h

//Sample for room:  Ã·×¯³ø·¿
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ã·×¯³ø·¿");



	add_door("Ã·×¯×ßÀÈ2", "Ã·×¯×ßÀÈ2", "Ã·×¯³ø·¿");
	add_npc("pub_chushi");	
	add_npc("meizhuang_danqingsheng");	

    

/******************************************************************************
        set("exits", ([  
            "south" : __DIR__"zoulang3",
        ]));
        set("objects", ([  
            __DIR__"npc/chushi" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
