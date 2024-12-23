//tianxiang.h

//Sample for room: 天香堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_tianxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天香堂");
	
	add_npc("heimuya_shang");     //add by zdn 2001-07-20


	add_door("黑木崖天香堂大厅", "黑木崖天香堂大厅", "黑木崖天香堂");

	set("long", "这里是黑木崖的第四大堂“天香堂”。一中年妇人横眉立在当地。");

/*****************************************************
        set("exits", ([
            "northdown"   : __DIR__"dating4",
        ]));
        set("objects", ([
            __DIR__"npc/shang" : 1,
        ]));       
//        
********************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp