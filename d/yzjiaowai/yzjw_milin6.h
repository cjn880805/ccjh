//milin6.h

//Sample for room:  ����������6
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_milin6);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������6");

	//add npcs into the room
	add_npc("animal_dog");        //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("����������5","����������5","����������6");
	add_door("����������7","����������7","����������6");

    set("long","����һƬï�ܵ������֣�һ�߽�������·���ʧ�˷���");
	

/********************************************************
	set("exits", ([
		"east" : __FILE__,
		"west" : __DIR__"ml7",
		"south" : __DIR__"dongmen",
		"north" : __FILE__,
	]));
	
********************************************************/
 
};


ROOM_END;
