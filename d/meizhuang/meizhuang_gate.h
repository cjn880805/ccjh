//gate.h

//Sample for room:  梅庄大门
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_gate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄大门");
	
	add_npc("pub_daoke");     //add by zdn 2001-07-14
	add_item("meishu");

	add_door("梅庄蜿蜒小径", "梅庄蜿蜒小径", "梅庄大门");
	add_door("梅庄大天井", "梅庄大天井", "梅庄大门");
	

/******************************************************************************
        set("exits", ([  
            "south"    : __DIR__"xiaolu",
        ]));
        
******************************************************************************/
};


ROOM_END;
