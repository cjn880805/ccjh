//baiyunan.h

//Sample for room: 白云庵
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRHengShan2_baiyunan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白云庵");

	//add npcs into the room

	add_npc("hengshan_zhengyue");
	add_npc("hengshan_yiqing");

				
	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("恒山见性峰广场", "恒山见性峰广场", "恒山白云庵");

    set("long","这里就是恒山派掌门人的居所。庵内供奉白衣观世音，除地上一个蒲团，四壁萧然。恒山派威震江湖，没想到主庵居然简朴一至如斯。" );

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"square",
        ]));
	set("objects", ([
		__DIR__"npc/xian" : 1,
		__DIR__"npc/zheng" : 1,
		__DIR__"npc/qin" : 1,
	]));
********************************************/
};


ROOM_END;
