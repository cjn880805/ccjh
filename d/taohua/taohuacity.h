//taohuacity.h

//Sample for room: 桃花岛
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTaoHuacity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "桃花岛");

	add_npc("taohua_feng");

	add_door("嘉兴南门", "嘉兴南门", "桃花岛");
	add_door("桃花岛墓道", "桃花岛墓道", "桃花岛");
	add_door("桃花岛山洞", "桃花岛山洞", "桃花岛");
	add_door("桃花山庄正门", "桃花山庄正门", "桃花岛");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp