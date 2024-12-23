//xingsu.h

//Sample for room: 星宿派
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_xingsu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "星宿派");


	add_door("天山山路2", "天山山路2", "西域星宿派");

};


XIYU_END;
//last, register the room into ../server/RoomSetup.cpp