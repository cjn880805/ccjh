//milin4.h

//Sample for room:  ����������4
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_milin4);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������4");

	//add npcs into the room

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("����������3","����������3","����������4");
	add_door("����������5","����������5","����������4");

    set("long","����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���");
	

/********************************************************
	set("exits", ([
		"east" : __FILE__,
		"west" : __FILE__,
		"south" : __DIR__"dongmen",
		"north" : __DIR__"ml5",
	]));
********************************************************/
 
};


ROOM_END;
