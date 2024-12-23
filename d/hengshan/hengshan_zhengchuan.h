//zhengchuan.h

//Sample for room: 衡山正川门
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_zhengchuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山正川门");
	
	add_npc("henshan_qu");        //add by zdn 2001-07-20


	add_door("衡山奎星阁", "衡山奎星阁", "衡山正川门");
	add_door("衡山御碑亭", "衡山御碑亭", "衡山正川门");

    set("long","正川门是南岳大庙的第三进。院内是玄德宗殿，关圣殿，观音阁等楼宇。 " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"kuixingge",
           "north"  : __DIR__"yubeiting",
        ]));
********************************************/
};


ROOM_END;
