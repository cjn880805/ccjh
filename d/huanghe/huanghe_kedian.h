//kedian.h

//Sample for room: 黄河客店
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄河客店");

	//add npcs into the room
	add_npc("pub_xiaoer2");

	add_door("黄河永登", "黄河永登", "黄河客店");
	add_door("黄河马厩", "黄河马厩", "黄河客店");

	set("long","这是一家当地居民开的鸡毛小店，楼下卖些卤菜和劣酒，楼上则是客房。这是在进祈连山区前的唯一休息之处，贩夫走卒，采药客等皆在此休憩，不时还可看见一两个寻仙访道之辈。墙上有一块牌子(paizi)，西面是一间马厩。");
    
    set("no_fight", 1);
    set("valid_startroom", 1);
    set("sleep_room",1);

/*****************************************************
        set("item_desc", ([
                "paizi" : "楼上雅房，每夜五两白银。\n",
        ]));

        set("objects", ([
                "/d/hangzhou/npc/xiaoer" : 1,
        ]));

        set("exits", ([
                "west" : __DIR__"majiu",
                "east" : __DIR__"yongdeng",
                "up"   : __DIR__"kedian2",
        ]));
********************************************/
};


CHANGAN_END;
