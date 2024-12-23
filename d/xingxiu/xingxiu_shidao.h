//shidao.h

//Sample for room: 星宿海石道
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_shidao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海石道");
        add_npc("xingxiu_caihua");
	add_door("星宿海", "星宿海", "星宿海石道");
	add_door("星宿海逍遥洞", "星宿海逍遥洞", "星宿海石道");

    set("long","这是星宿海边有人用石头铺成的一条小道，周围弥漫着沼泽的瘴气和一种说不出来的香味。路边有个石洞。" );

/*****************************************************
        set("exits", ([ 
            "east" : __DIR__"xxh4",
            "enter" : __DIR__"xiaoyao",
        ]));
        set("objects", ([ 
            __DIR__"npc/caihua" : 1,
        ]) );
********************************************/
};


ROOM_END;
