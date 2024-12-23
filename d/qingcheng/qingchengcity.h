//qingcheng.h

//Sample for room  青城
//coded by zwb
//data: 2000-11-18

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRQingChengcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "青城");
	
	add_npc("qingcheng_shen");       //add by zdn 2001-07-20

	add_npc("pub_playboy");

	add_door("青城青石大道", "青城青石大道", "出口");

};


ROOM_END;
