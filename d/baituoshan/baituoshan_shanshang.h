//shanshang.h

//Sample for room:  白驼山山上
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_shanshang);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "白驼山山上");


	add_door("白驼山山脚", "白驼山山脚", "白驼山山上");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp