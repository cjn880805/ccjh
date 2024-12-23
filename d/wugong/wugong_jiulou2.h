//jiulou2.h

//Sample for room: 武功酒楼二楼
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_jiulou2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "武功酒楼二楼");


	add_door("武功酒楼", "武功酒楼", "武功酒楼二楼");


/*****************************************************
        set("item_desc", ([
                "paizi" : "本店出售烤鸭及上等花雕酒。\n",
        ]));
        set("objects", ([
                __DIR__"npc/zhanggui" : 1,
        ]));

        set("exits", ([
                "down" : __DIR__"jiulou1",
        ]));
********************************************/
};


WUGONG_END;
