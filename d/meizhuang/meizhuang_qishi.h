//qishi.h

//Sample for room:  ÷ׯ����
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_qishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����");

	add_door("÷ׯ����2", "÷ׯ����2", "÷ׯ����");
	add_npc("meizhuang_heibaizi");	

    

/******************************************************************************
        set("exits", ([  
            "east" : __DIR__"zoulang2",
        ]));
        set("objects", ([  
             __DIR__"npc/heibai-zi.c" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
