//hengshan2.h

//Sample for room  ∫„…Ω
//coded by zwb
//data: 2000-11-17

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRHengShancity2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "∫„…Ω");
	
	add_npc("hengshan_yafu");       //add by zdn 2001-07-20



};


ROOM_END;
