//yubeiting.h

//Sample for room: 衡山御碑亭
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_yubeiting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山御碑亭");
	
	add_npc("henshan_xiaoqu");        //add by zdn 2001-07-20


	add_door("衡山正川门", "衡山正川门", "衡山御碑亭");
	add_door("衡山嘉应门", "衡山嘉应门", "衡山御碑亭");

    set("long","御碑为重修南岳庙大石碑，高数丈，石碑竖立在重三万八千斤的大石龟上，龟身雕刻细腻，极为生动。 " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"zhengchuan",
           "north"  : __DIR__"jiayingmen",
        ]));
********************************************/
};


ROOM_END;
