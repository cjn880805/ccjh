//mingjiao.h



//Sample for room:  明教昆仑山下

//coded by zouwenbin

//data: 2000-11-16

ROOM_BEGIN(CRMingJiaocity);


virtual void create()			//Call it when Room Create

{
	//set name of our room

	set_name( "明教昆仑山下");

	add_npc("helpnpc003");		//add by qzj 2001-08-13
	add_npc("pub_dusha");

	add_door("西域丝绸之路3", "西域丝绸之路3", "明教昆仑山下");
	add_door("明教青石大道1", "明教青石大道1", "明教昆仑山下");


};

ROOM_END;
