//zoulang1.h

//Sample for room:  梅庄走廊1
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_zoulang1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄走廊1");
	
	add_npc("pub_boy");     //add by zdn 2001-07-14

	add_door("梅庄内院", "梅庄内院", "梅庄走廊1");
	add_door("梅庄走廊2", "梅庄走廊2", "梅庄走廊1");
	add_door("梅庄书室", "梅庄书室", "梅庄走廊1");
	add_door("梅庄画室", "梅庄画室", "梅庄走廊1");
	
	set("long", "这是一条长长的走廊，走廊两边是四位庄主中的其他三位平时休息和练功的地方，这里的左边是书室，右边是画室，三庄主秃笔翁和四庄主丹青生在闲来无事的时候，便到那里面去挥毫，泼墨。   " );
    

/******************************************************************************
        set("exits", ([ 
            "west" : __DIR__"shushi",
            "east" : __DIR__"huashi",
            "north" : __DIR__"zoulang2",
            "south" : __DIR__"neiyuan",
        ]));
******************************************************************************/
};


ROOM_END;
