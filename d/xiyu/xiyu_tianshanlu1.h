//tianshanlu1.h

//Sample for room: 天山山路1
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_tianshanlu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "天山山路1");
	
	add_npc("monster_28k");         //add by zdn 2001-07-16


	add_door("西域天山山路2", "西域天山山路2", "西域天山山路1");
	add_door("西域天山脚下", "西域天山脚下", "西域天山山路1");

};


XIYU_END;
