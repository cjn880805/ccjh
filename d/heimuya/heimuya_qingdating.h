//qingdating.h

//Sample for room: 青龙堂大厅
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_qingdating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青龙堂大厅");
	
	add_npc("heimuya_zhang2");     //add by zdn 2001-07-20


	add_door("黑木崖长廊2", "黑木崖长廊2", "黑木崖青龙堂大厅");
	add_door("黑木崖令牌堂", "黑木崖令牌堂", "黑木崖青龙堂大厅");

	set("long", "这是『日月神教』下第三大堂：青龙堂的大厅。一位长者居中，神情恍惚。(bian)。");
    

/*****************************************************
        set("exits", ([
            "north" : __DIR__"chlang2",
            "east" : __DIR__"tang",
        ]));
        set("objects",([
            __DIR__"npc/jiabu"   :1,
        ]));
********************************************/
};


ROOM_END;
