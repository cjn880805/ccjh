//sichouzilu2.h

//Sample for room: ˿��֮·2
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_sichouzilu2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˿��֮·2");
	
	add_npc("monster_4k");        //add by zdn 2001-07-16
//	add_npc("kunlun_xihuazi");        //add by zdn 2001-07-20

	add_door("����˿��֮·1", "����˿��֮·1", "����˿��֮·2");
	add_door("����˿��֮·3", "����˿��֮·3", "����˿��֮·2");

};


XIYU_END;
