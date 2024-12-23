//shenggu.h

//Sample for room: 圣姑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_shenggu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "圣姑堂");

	//add npcs into the room
	add_npc("pub_shinu");
	add_npc("heimuya_renyingying");      // add by zdn 2001-07-20

	add_door("黑木崖白虎堂", "黑木崖白虎堂", "黑木崖圣姑堂");

	set("long", "这里是黑木崖的圣姑所在地“圣姑堂”。堂上五彩云罗，煞是漂亮。堂中一位妙龄女子，青衫小袖，明艳不可方物。");

/*****************************************************
        set("exits", ([
            "east"   : __DIR__"chitang",
        ]));
        set("objects", ([
            __DIR__"npc/ren" : 1,
            __DIR__"npc/shinu":2,
        ]));       
//        
********************************************/
};


ROOM_END;
