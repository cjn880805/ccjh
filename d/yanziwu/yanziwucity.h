//yanziwucity.h

//Sample for room:  �����볤��
//coded by Fisho
//data: 2000-11-4

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRyanziwucity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����볤��");
	add_npc("murong_feng");        //add by zdn 2001-07-20

	add_door("����������Է", "����������Է", "�����볤��");
	add_door("���������԰", "���������԰", "�����볤��");
	add_door("�������Խ�̨", "�������Խ�̨", "�����볤��");

/********************************************************
 
****************************************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp