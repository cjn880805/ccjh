//hengshan.h

//Sample for room  衡山
//coded by zwb
//data: 2000-11-17

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHengShancity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "衡山");
	
//	add_npc("pub_jianke");         //add by zdn 2001-07-16


	add_door("衡阳城", "衡阳城", "出口");


};


ROOM_END;
