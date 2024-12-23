//shanjian.h

//Sample for room: 衡山山涧
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan_shanjian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山山涧");


	add_door("衡山方广寺", "衡山方广寺", "衡山山涧");
	add_door("衡山黑沙潭", "衡山黑沙潭", "衡山山涧");

    set("long","顺山涧漂流而下，沿溪遍布珍稀树木，泉石，林木，花草及峰峦均极宜人。涧流至崖折叠飞泄而下，声震山谷。" );
    

/*****************************************************
        set("exits", ([ 
           "down"     : __DIR__"heishatan",
           "northup"  : __DIR__"fangguangsi",
        ]));
********************************************/
};


ROOM_END;
