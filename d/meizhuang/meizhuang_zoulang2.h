//zoulang2.h

//Sample for room:  梅庄走廊2
//coded by zouwenbin
//data: 2000-12-2

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRMeiZhuang_zoulang2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "梅庄走廊2");
	
	add_npc("pub_lady3");       //add by zdn 2001-07-14

	add_door("梅庄走廊1", "梅庄走廊1", "梅庄走廊2");
	add_door("梅庄厨房", "梅庄厨房", "梅庄走廊2");
	add_door("梅庄休息室", "梅庄休息室", "梅庄走廊2");
	add_door("梅庄棋室", "梅庄棋室", "梅庄走廊2");
	
	set("long", "这是一条长长的走廊，走廊两边是四位庄主中的其他三位平时休息和练功的地方，这里的左边是棋室，右边则是梅庄弟子感觉劳顿的时候休息的地方，二庄主黑白子不分昼夜都在棋室里研究他那些不知道哪儿找来的古棋谱。 " );
    

/******************************************************************************
        set("exits", ([  
            "west" : __DIR__"qishi",
            "east" : __DIR__"xiuxishi",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
        ]));
******************************************************************************/
};


ROOM_END;
