//minju2.h

//Sample for room: 民居2
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_minju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "民居2");


	add_door("襄阳东南", "襄阳东南", "襄阳民居2");

	set("long", "这是一家比较有钱人的住房，房子主人正在家里忙这忙那，看见你进来，急忙站起身向你打招呼。" );
	
/*****************************************************
	set("exits", ([
		"east" : __DIR__"jiedao",
	]));
********************************************/
};


ROOM_END;
