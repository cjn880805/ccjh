//shiziyan.h

//Sample for room: 衡山狮子岩
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shiziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山狮子岩");


	add_door("衡山南天门", "衡山南天门", "衡山狮子岩");
	add_door("衡山望日台", "衡山望日台", "衡山狮子岩");

    set("long","  狮子岩布满奇形怪状的岩石，细究则绝类狮子，腾跃伏吼，各肖其类。到狮子岩，祝融峰已经在望了。" );
    

/*****************************************************
        set("exits", ([ 
           "southwest"  : __DIR__"nantian",
           "northup"    : __DIR__"wangritai",
        ]));
********************************************/
};


ROOM_END;
