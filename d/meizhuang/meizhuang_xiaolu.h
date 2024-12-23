//xiaolu.h

//Sample for room:  梅庄蜿蜒小径
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄蜿蜒小径");
	
	add_npc("animal_dog");        //add by zdn 2001-07-14
	add_item("meishu");

	add_door("梅庄孤山石级", "梅庄孤山石级", "梅庄蜿蜒小径");
	add_door("梅庄大门", "梅庄大门", "梅庄蜿蜒小径");
	

    

/******************************************************************************
        set("exits", ([  
            "south" : __DIR__"shijie",
            "north" : __DIR__"gate",
        ]));
        set("outdoors", "meizhuang");
******************************************************************************/
};


ROOM_END;
