//daxiaochang.h

//Sample for room: 大校场
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_daxiaochang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大校场");


//	add_door("襄阳西北", "襄阳西北", "襄阳大校场");

	set("outdoors", "xiangyang");
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"westjie3",
	]));
********************************************/
};


ROOM_END;
