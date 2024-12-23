//xiaomiao.h

//Sample for room: 武功土地庙
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_xiaomiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武功土地庙");


	add_door("武功", "武功", "武功土地庙");


/*****************************************************
        set("exits", ([
                "north" : __DIR__"xijie",
        ]));

        set("objects", ([
                __DIR__"npc/dipi" : 1,
        ]));
********************************************/
};


WUGONG_END;
