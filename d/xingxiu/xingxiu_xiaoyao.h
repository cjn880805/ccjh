//xiaoyao.h

//Sample for room: 星宿海逍遥洞
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xiaoyao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿海逍遥洞");

	add_door("星宿海石道", "星宿海石道", "星宿海逍遥洞");

    
    add_npc("xingxiu_azi");
    add_npc("zm_xingxiu");
    add_npc("xingxiu_shihou");
    set("sleep_room", 1);

/*****************************************************
        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));
        set("item_desc", ([
                "wall" : "星宿淫贼人人得而株之！\n",
        ]) );
********************************************/
};


ROOM_END;
