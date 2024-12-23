//hangzhoucity.h

//Sample for room:  杭州
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRhangzhoucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州");
	
	add_npc("pub_girl1");
	add_npc("pub_boy");     //add by zdn 2001-07-14
	add_npc("helpnpc013");		//add by qzj 2001-08-13

	add_door("嘉兴城", "嘉兴城", "出口");
	add_door("福州", "福州", "出口");

	add_door("杭州青石大道1", "杭州青石大道1", "出口");


/********************************************************
 
****************************************************************/
};


ROOM_END;
