//banshanting.h

//Sample for room: 终南山半山亭
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_banshanting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "终南山半山亭");
	

	add_npc("pub_youke");
	
	add_door("终南山石阶5", "终南山石阶5", "终南山半山亭");

    set("long","这里是半山腰的一个小凉亭，游客们爬山爬的累了，就转个弯到这里来坐一坐，歇一歇脚。从这里看下去，刚好可以看见翠屏峰的峰顶。" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"shijie5",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
