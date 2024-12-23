//zhandao.h
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_zhandao);

virtual void create()			//Call it when Room Create
{

	//set name of our room

	set_name( "明教栈道");

	add_door("明教烈火旗大厅", "明教烈火旗大厅", "明教栈道");
	add_door("明教天微堂", "明教天微堂", "明教栈道");

	set("long", "这里是通往明教的栈道，脚下茂林生云，极其艰险。");
    

/*****************************************************
	set("exits", ([
		"northup"   : __DIR__"zhandao2",
		"southdown" : __DIR__"lhqhoumen",
	]));
	set("outdoors", "mingjiao");
	
********************************************/

};



ROOM_END;
