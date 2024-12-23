//dating.h

//Sample for room:  梅庄四雅清风
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄四雅清风");

	add_door("梅庄大天井", "梅庄大天井", "梅庄四雅清风");
	add_door("梅庄迎客亭", "梅庄迎客亭", "梅庄四雅清风");
	

    

/******************************************************************************
        set("item_desc", ([  
            "bian" : "这块匾已经很陈旧了，看起来摇摇晃晃的，似乎不大结实。\n",
        ]));
        set("exits", ([  
            "north" : __DIR__"keting",
            "south" : __DIR__"tianjing",
        ]));
******************************************************************************/
};


ROOM_END;
