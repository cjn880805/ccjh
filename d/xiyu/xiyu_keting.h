//keting.h

//Sample for room: 巴依家客厅
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_keting);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "巴依家客厅");
	
	add_npc("pub_lady3");     //add by zdn 2001-07-016

	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("小坝", "永登小坝", "西域巴依家客厅");

};

	

XIYU_END;
//last, register the room into ../server/RoomSetup.cpp