//shushi.h

//Sample for room:  ÷ׯ����
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_shushi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����");

	add_door("÷ׯ����1", "÷ׯ����1", "÷ׯ����");
	add_npc("meizhuang_tubiweng");
		

    

/******************************************************************************
        set("exits", ([  
            "east" : __DIR__"zoulang1",
        ]));
        set("objects", ([  
            __DIR__"npc/tubi-weng.c" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
