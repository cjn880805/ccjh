//shandong.h

//Sample for room: 山洞
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_shandong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山洞");


	add_door("桃花岛", "桃花岛", "桃花岛山洞");

	set("long", "你正处在一个小山洞中。这里光线很暗，只能隐隐约约看出地上有一堆干草。干草上好象放着一个石匣(xia)。 你突然闻到一股难闻的气味，显然是有人长期住在这里却不打扫的缘故。");

/*****************************************************
        set("item_desc", ([
        "xia" : @TEXT
        你仔细看了一下石匣，发现里面似乎放着一本书，似乎可以试着拿出来(pick book)。
        TEXT ]) );
        set("exits", ([
            "out"  : __DIR__"road5",
        ]));
        set("objects", ([
            __DIR__"npc/zhou" : 1,
        ]) );    
********************************************/
};


ROOM_END;
