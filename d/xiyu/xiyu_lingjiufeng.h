//lingjiufeng.h

//Sample for room: ���շ�
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
	set_name( "���շ�");
	
	add_npc("pub_youke");       //add by zdn 20001-07-16

	add_door("��ɽɽ·2", "��ɽɽ·2", "�������շ�");

};



XIYU_END;
//last, register the room into ../server/RoomSetup.cpp