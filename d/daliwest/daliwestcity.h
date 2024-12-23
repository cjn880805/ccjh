//daliwest.h

//Sample for room:  �������
//coded by zouwenbin
//data: 2000-11-15

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRDaLiWestcity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");
	
	add_npc("pub_shiwei1");   //add by zdn 2001-07-13
	add_npc("dali_bing");       //add by zdn 2001-07-20

	add_door("�����", "�����", "����");

	add_door("��������������", "��������������", "����");
	add_door("��������黨��", "��������黨��", "����");
	add_door("��������������", "��������������", "����");

};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp