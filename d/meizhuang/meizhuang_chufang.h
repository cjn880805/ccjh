//chufang.h

//Sample for room:  ÷ׯ����
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ����");



	add_door("÷ׯ����2", "÷ׯ����2", "÷ׯ����");
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
