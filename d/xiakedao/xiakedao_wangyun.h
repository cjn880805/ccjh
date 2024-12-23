//wangyun.h

//Sample for room: 侠客岛望云台
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_wangyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛望云台");
	
	add_npc("xiakedao_shizhongyu");        //add by zdn 2001-07-20

	add_door("侠客岛一线天", "侠客岛一线天", "侠客岛望云台");
    
//	add_npc("xiake_yanruoshui");

/*****************************************************
        set("exits", ([
                "northdown" : __DIR__"road8",
        ]));
        set("outdoors", "xiakedao" );
        set("item_desc",([
            "cao" : "几珠碧绿的小草，你不禁想拿(take)起来。\n"
        ]) );
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp