//lingjiufeng.h

//Sample for room: 灵鹫峰
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_lingjiufeng);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "灵鹫峰");
	
	add_npc("pub_youke");       //add by zdn 20001-07-16

	add_door("天山山路2", "天山山路2", "西域灵鹫峰");

};



XIYU_END;
//last, register the room into ../server/RoomSetup.cpp