//huayuan.h

//Sample for room: 黑木崖顶小花园
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_huayuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黑木崖顶小花园");
	
	add_npc("ry_dongfang");

	add_door("黑木崖顶通道6层", "黑木崖顶通道6层", "黑木崖顶小花园");
	add_door("小花园", "黑木崖小花园", "黑木崖顶小花园");

	set("long", "从昏暗的地道中出来，你发现自己竟是置身于一个极精致的小花园中，红梅绿竹，青松翠柏，布置得颇具匠心，往东去是一间精雅小舍。 ");
    
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp