//fu_xiaoyuan.h

//Sample for room: 富家小院
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_xiaoyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "富家小院");
	add_npc("pub_poorman");


	add_door("武功富家大门", "武功富家大门", "武功富家小院");
	add_door("武功富家大堂", "武功富家大堂", "武功富家小院");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"fu-damen",
                "south" : __DIR__"fu-datang",
                "west" : __DIR__"fu-cemen",
                "east" : __DIR__"fu-huating",
        ]));
        set("objects", ([
                __DIR__"npc/poorman" : 2,
        ]));
********************************************/
};


WUGONG_END;
