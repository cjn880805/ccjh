//xiaowu.h

//Sample for room:  ÷ׯС��
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_xiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯС��");

	add_door("÷ׯ����СԺ", "÷ׯ����СԺ", "÷ׯС��");
	add_npc("meizhuang_huangzhonggong");
		


/******************************************************************************
        set("exits", ([  
            "out" : __DIR__"xiaoyuan",
        ]));
        set("objects", ([  
            __DIR__"npc/huangzhong-gong" : 1,
            __DIR__"obj/wall" : 0,
        ]));
******************************************************************************/
};


ROOM_END;
