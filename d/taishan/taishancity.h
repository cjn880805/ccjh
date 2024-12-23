//taishan.h

//Sample for room  泰山
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTaiShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "泰山");

	add_npc("helpnpc016");		//add by qzj 2001-08-13

	add_door("嘉兴城", "嘉兴城", "出口");
};

ROOM_END;
