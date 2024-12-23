//beiyuemiao.h

//Sample for room: 恒山北岳庙
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_beiyuemiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山北岳庙");

	//add npcs into the room
	add_npc("hengshan_yihe");

	add_door("恒山果老岭", "恒山果老岭", "恒山北岳庙");
	add_door("恒山见性峰山道1", "恒山见性峰山道1", "恒山北岳庙");

    set("long","北岳庙是个巍巍壮观的宫殿庙宇，山门三重，高列阜上，其下石阶数层。这里是北岳庙最大最高的 '朝殿' 。 " );
    

/*****************************************************
        set("exits", ([ 
           "east"      : __DIR__"kutianjing",
           "west"      : __DIR__"jijiaoshi",
           "northup"   : __DIR__"beiyuedian",
           "southdown" : __DIR__"guolaoling",
        ]));
	set("objects", ([
		__DIR__"npc/he" : 1,
	]));
********************************************/
};


ROOM_END;
