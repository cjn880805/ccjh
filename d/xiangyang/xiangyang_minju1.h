//minju1.h

//Sample for room: 民居1
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_minju1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "民居1");
	
	add_npc("pub_linjinzhi");

	add_door("襄阳东南", "襄阳东南", "襄阳民居1");

	set("long", "这是一家比较有钱人的住房，房子主人正在家里忙这忙那，看见你进来，急忙站起身向你打招呼。" );
	
/*****************************************************
	set("exits", ([
		"west" : __DIR__"jiedao",
	]));
********************************************/
};


ROOM_END;
