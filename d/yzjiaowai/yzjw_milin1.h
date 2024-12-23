//milin1.h

//Sample for room:  扬州青竹林1
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_milin1);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州青竹林1");

	//add npcs into the room
	add_npc("monster_4K");        //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州东门","扬州东门","扬州青竹林1");
	add_door("扬州青竹林2","扬州青竹林2","扬州青竹林1");

    set("long","这是一间破破烂烂的土地庙，庙里破败不堪，土地神像推在一旁，梁上地下也布满了灰尘。一看就知道已经很久没有人来清理过了。正中放着个大香案，上面零乱地扔着几根吃剩下来的鸡骨头。也许正是因为隐蔽的原因吧，据说丐帮江南分舵就被设在此处。香案黑洞洞的，好象下边有个大洞(dong)。");
	

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
