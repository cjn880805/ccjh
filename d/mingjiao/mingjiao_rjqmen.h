//rjqmen.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_rjqmen);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "锐金旗大门");

	add_door("天微堂", "明教天微堂", "锐金旗大门");
	add_door("天微堂", "明教天微堂", "锐金旗大门");

    

/*****************************************************
	set("exits", ([
		"enter" : __DIR__"rjqyuan",
		"east" : __DIR__"torjq3",
	]));
********************************************/

};



ROOM_END;
