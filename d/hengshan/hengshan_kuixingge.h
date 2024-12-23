//kuixingge.h

//Sample for room: 衡山奎星阁
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_kuixingge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山奎星阁");

	add_door("衡山钟亭", "衡山钟亭", "衡山奎星阁");
	add_door("衡山棂星门", "衡山棂星门", "衡山奎星阁");
	add_door("衡山正川门", "衡山正川门", "衡山奎星阁");

    set("long","奎星阁是南岳大庙的第二进。阁为一个大舞台，阁左为鼓亭，右是钟亭。乡俗年节唱戏，这里总是热闹非凡。 " );
    

/*****************************************************
        set("exits", ([  
           "south"  : __DIR__"lingxingmen",
           "east"   : __DIR__"zhongting",
           "north"  : __DIR__"zhengchuan",
        ]));
********************************************/
};


ROOM_END;
