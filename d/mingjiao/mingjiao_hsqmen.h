//hsqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_hsqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "洪水旗大门");

	add_door("天微堂", "明教天微堂", "洪水旗大门");
	add_door("天微堂", "明教天微堂", "洪水旗大门");

	set("long", "这里是明教洪水旗的大门, 庄严古朴, 门前对插四面镶蓝蟠龙旗门前水声潺潺, 却是一条水流从门下流出, 正是瀑布的上源,原来, 整个洪水旗就建筑在这条小河之上");
    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"tohsq7",
	]));
********************************************/

};



ROOM_END;
