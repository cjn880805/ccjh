//xiyu.h

//Sample for room: 西域
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "西域");
	
	add_npc("monster_6k");      //add by zdn 2001-07-16
//	add_npc("kunlun_yulingzi");        //add by zdn 2001-07-20

	add_door("襄阳城", "襄阳城", "出口");

	add_door("西域大漠", "西域大漠", "出口");

};


XIYU_END;
