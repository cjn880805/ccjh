//yzjw_nanxun.h

//Sample for room:  扬州南浔
//coded by zwb
//data: 2000-11-20

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_nanxun);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州南浔");

	//add npcs into the room
	add_npc("pub_bing");          //add by zdn 2001-07-16

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州宜兴","扬州宜兴","扬州南浔");

};


ROOM_END;
