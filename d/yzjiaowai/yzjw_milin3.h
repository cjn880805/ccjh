//milin3.h

//Sample for room:  扬州青竹林3
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_milin3);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州青竹林3");

	//add npcs into the room
	add_npc("pub_xianren");        //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州青竹林2","扬州青竹林2","扬州青竹林3");
	add_door("扬州青竹林4","扬州青竹林4","扬州青竹林3");

    set("long","这是一片茂密的青竹林，一走进来，你仿佛迷失了方向。");
	

/********************************************************
	set("exits", ([
		"east" : __DIR__"ml2",
		"west" : __FILE__,
		"south" : __DIR__"dongmen",
		"north" : __FILE__,
	]));
********************************************************/
 
};


ROOM_END;
