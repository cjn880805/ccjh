//wanjie.h

//Sample for room  万劫谷
//coded by zwb
//data: 2000-11-19

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRWanJiecity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "万劫谷");
	
	add_npc("wanjie_mu");        //add by zdn 2001-07-20

	add_door("襄阳城", "襄阳城", "出口");

	add_door("万劫谷江边小路1", "万劫谷江边小路1", "出口");

};


ROOM_END;
