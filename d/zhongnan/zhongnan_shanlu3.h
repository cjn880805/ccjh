//shanlu3.h

//Sample for room: 终南山山路3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山山路3");
	
	//add npcs into the room   2001=07-10 zdn add
	add_npc("quanzhen_daotong");

	add_door("终南山山路2", "终南山山路2", "终南山山路3");
	add_door("终南山翠屏谷", "终南山翠屏谷", "终南山山路3");

	set("long","这里是山路的尽头，南面好象有一片小树林，折而向东，就是终南山的山脚了。" );
    

/*****************************************************
        set("exits", ([
                "southwest" : __DIR__"shanlu2",
                "northup" : __DIR__"cuipinggu",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
