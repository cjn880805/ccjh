//yzjw_shanlu1.h

//Sample for room:  扬州山路1
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shanlu1);


virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "扬州山路1");
	//add npcs into the room
	add_npc("pub_jianke");      // add by zdn 2001-07-16

	add_door("扬州树林","扬州树林","扬州山路1");

	add_door("扬州青竹林2","扬州青竹林2","扬州山路1");


};


ROOM_END;
