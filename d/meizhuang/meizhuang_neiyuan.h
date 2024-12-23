//neiyuan.h

//Sample for room:  梅庄内院
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_neiyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄内院");
	
	add_npc("pub_shiwei");            // add by zdn 2001-07-14
	add_npc("pub_wuxing");
	add_item("meishu");

	add_door("梅庄百木园", "梅庄百木园", "梅庄内院");
	add_door("梅庄走廊1", "梅庄走廊1", "梅庄内院");
	
	set("long", "这里是梅庄的内院，从这里走过去就可以找到四位庄主，这里似乎非常安静，可以听见落叶触地的声音，但又似乎非常吵闹，经常可以听到嘈杂的琴声，但这琴声又可以将你的心弦打乱，你真不知道该怎么形容这个地方。有一位壮年的汉子，腰悬宝剑守在院门口。   " );
    

/******************************************************************************
        set("outdoors", "meizhuang");
        set("exits", ([  
            "south" : __DIR__"senlin1",
            "north" : __DIR__"zoulang1",
        ]));
        set("objects", ([  
            __DIR__"npc/huyuan.c" : 1,
        ]));
******************************************************************************/
};


ROOM_END;




