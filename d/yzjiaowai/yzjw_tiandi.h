//yzjw_tiandi.h

//Sample for room:  扬州田地
//coded by zwb
//data: 2000-11-20

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_tiandi);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州田地");

	//add npcs into the room
	add_npc("pub_nongfu2");      //add by zdn 2001-07-16
	add_item("daotian");

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("扬州树林","扬州树林","扬州田地");
	add_door("扬州宜兴","扬州宜兴","扬州田地");

};


ROOM_END;
