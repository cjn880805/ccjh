//dalieast.h

//Sample for room:  ����Ƕ�
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiEastcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ƕ�");

	add_npc("pub_playboy");  //add by zdn 2001-07-12

	add_door("�����", "�����", "����");
	add_door("����������", "����Ƕ������", "����");
	add_door("��������Ϸ�", "����Ƕ����Ϸ�", "����");

};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp



