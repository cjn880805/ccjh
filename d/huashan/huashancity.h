//huashancity.h

//Sample for room: 华山
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHuaShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "华山");

	//add npcs into the room

	add_npc("helpnpc012");		//add by qzj 2001-08-13

	add_door("襄阳城", "襄阳城", "出口");
	add_door("黑木崖", "黑木崖", "出口");
	add_door("华山村", "华山村", "出口");
	add_door("舍身崖", "舍身崖", "出口");

	add_door("华山脚下", "华山脚下", "出口");



};


ROOM_END;
