//shop.h

//Sample for room: 杂货店
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_shop);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杂货店");

	//add npcs into the room
	add_npc("wudang_lisi");

	add_door("华山村", "华山村", "华山村杂货店");

  	set("long","这是一间小小的杂货店，经营些油、盐、酱、醋及日用百货，村子里的人多数是很穷，除了生活必需品，这里很少贩卖其它物品。" );

/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"eroad3",
        ]));
//        
        set("objects", ([
            __DIR__"npc/xiejian": 1
        ]) );
********************************************/
};


ROOM_END;
