//shijianyan.h

//Sample for room: 终南山试剑岩
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijianyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山试剑岩");

	add_npc("quanzhen_daotong");

	
	add_door("终南山石阶4", "终南山石阶4", "终南山试剑岩");
	add_door("终南山教碑", "终南山教碑", "终南山试剑岩");
	add_door("终南山石阶8", "终南山石阶8", "终南山试剑岩");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                __DIR__"npc/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
