//xiaoshe.h

//Sample for room: 小舍
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_xiaoshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "小舍");
	
	add_npc("pub_lady3");       // add by zdn 2001-07-14


	add_door("黑木崖小花园", "黑木崖小花园", "黑木崖小舍");
	add_door("黑木崖小舍内室", "黑木崖小舍内室", "黑木崖小舍");

	set("long", "这是一间用翠竹搭成的小舍。一进门，便闻到一阵浓烈的花香，房中挂着一幅仕女图，椅上铺了绣花锦垫，东边有一扇门，挂着绣了一丛牡丹的锦缎门帏。难道这是谁家姑娘的闺房？");
    

/*****************************************************
        set("exits", ([
            "east" : __DIR__"neishi",
            "out" :__DIR__"xiaohuayuan",
        ]));
********************************************/
};


ROOM_END;
