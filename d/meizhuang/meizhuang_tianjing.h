//tianjing.h

//Sample for room:  梅庄大天井
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_tianjing);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄大天井");
	add_item("meishu");

	add_door("梅庄大门", "梅庄大门", "梅庄大天井");
	add_door("梅庄四雅清风", "梅庄四雅清风", "梅庄大天井");
	

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
