//yzjw_shanlu2.h
//Sample for room:  扬州山路2
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_shanlu2);


virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "扬州山路2");
	
	add_npc("pub_punk");      //add by zdn 2001-07-16


	add_door("苏州青石官道2","苏州青石官道2","扬州山路2");

	add_door("扬州树林","扬州树林","扬州山路2");

};

ROOM_END;
