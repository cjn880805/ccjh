//cjlou.h

//Sample for room: 藏经阁一楼
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_cjlou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "藏经阁一楼");

	add_npc("shaolin_dao_yi");
	
	CBox * box = Add_Box();
	box->add_object("fojing11", 1);	
	box->set_name( "铁柜");		

	CBox * box1 = Add_Box();
	box1->add_object("fojing20", 1);	
	box1->set_name( "铁柜");	

	add_door("少林寺西竹林小道", "少林寺西竹林小道", "少林寺藏经阁一楼");
	add_door("少林寺藏经阁二楼", "少林寺藏经阁二楼", "少林寺藏经阁一楼");



};


ROOM_END;
