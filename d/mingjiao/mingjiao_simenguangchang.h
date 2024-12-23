//simenguangchang.h
//Sample for room: 刑堂
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_simenguangchang);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教四门广场");

	add_door("明教青石大道1", "明教青石大道1", "明教四门广场");

	add_door("明教天门男舍", "明教天门男舍", "明教四门广场");
	add_door("明教地门女舍", "明教地门女舍", "明教四门广场");
	add_door("明教雷门宿舍", "明教雷门宿舍", "明教四门广场");
	add_door("明教道家竹舍", "明教道家竹舍", "明教四门广场");

	set("long", "这里是一片庭院中央的广场，整个广场由大块的青石铺成，极为平坦。但因年代久远，都有些破损。丛丛小草从石板的缝隙中长了出来。广场四面有几条小道，通向明教的“天地风雷”四门。    冷谦执掌明教刑堂。");
    

/*****************************************************
        "north"     : __DIR__"mjsimen",
        "northwest" : __DIR__"mjtianmen",
        "northeast" : __DIR__"mjdimen",
        "southeast" : __DIR__"mjfengmen",
        "southwest" : __DIR__"mjleimen",
    ]));
    set("outdoors", "mingjiao");
********************************************/

};


ROOM_END;
