//yunge.h

//Sample for room: 恒山云阁虹桥
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_yunge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "恒山云阁虹桥");


	add_door("恒山梯式栈道", "恒山梯式栈道", "恒山云阁虹桥");
	add_door("恒山大字岭", "恒山大字岭", "恒山云阁虹桥");

    set("long","过完栈道，就到云阁虹桥。前往恒山主峰见性峰，都要在这里跨过唐峪河。拱桥卧波，水天亮丽，倍觉胸襟舒畅。 " );
    

/*****************************************************
        set("exits", ([ 
           "east"      : __DIR__"daziling",
           "northdown" : __DIR__"zhandao",
        ]));
	set("objects", ([
		__DIR__"npc/zhi" : 1,
	]));
********************************************/
};


ROOM_END;
