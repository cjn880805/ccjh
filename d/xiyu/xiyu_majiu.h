//majiu.h

//Sample for room: ���
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_majiu);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");
	
//	add_npc("pub_mafu");      //add by zdn 2001-07-16


	add_door("С��", "����С��", "�������");

};



XIYU_END;
//last, register the room into ../server/RoomSetup.cpp