//jiaobei.h

//Sample for room: 终南山教碑
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_jiaobei);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山教碑");

	add_npc("quanzhen_zhao");

	add_door("终南山试剑岩", "终南山试剑岩", "终南山教碑");
	add_door("终南山石阶6", "终南山石阶6", "终南山教碑");
	add_door("重阳宫大门", "重阳宫大门", "终南山教碑");
	
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie6",
                "eastup" : __DIR__"damen",
                "west" : __DIR__"shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ＊＊＊＊＊
　　　　＊　　　＊
　　　　＊　全　＊
　　　　＊　　　＊
　　　　＊　真　＊
　　　　＊　　　＊
　　　　＊　古　＊
　　　　＊　　　＊
　　　　＊　教　＊
　　　　＊　　　＊
　　　　＊＊＊＊＊
\n"NOR
        ]) );
        set("objects",([
                __DIR__"npc/zhao" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
