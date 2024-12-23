//songshan.h

//Sample for room:  嵩山
//coded by zouwenbin
//data: 2000-11-14

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRSongShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "嵩山");
	
	add_npc("pub_jianke");       //add by zdn 2001-07-15

	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("南阳", "南阳", "出口");
	add_door("少林寺", "少林寺", "出口");

	add_door("嵩山太室阙", "嵩山太室阙", "出口");


};


ROOM_END;
