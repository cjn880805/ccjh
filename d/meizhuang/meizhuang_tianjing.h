//tianjing.h

//Sample for room:  ÷ׯ���쾮
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_tianjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ׯ���쾮");
	add_item("meishu");

	add_door("÷ׯ����", "÷ׯ����", "÷ׯ���쾮");
	add_door("÷ׯ�������", "÷ׯ�������", "÷ׯ���쾮");
	

/******************************************************************************
        set("exits", ([ 
            "north" : __DIR__"dating",
        ]));
        set("objects", ([  
            __DIR__"npc/huyuan" : 1,
        ]));
******************************************************************************/
};


ROOM_END;
