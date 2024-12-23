//taohuacity.h

//Sample for room: �һ���
//coded by zwb
//data: 2000-11-16

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTaoHuacity);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�һ���");

	add_npc("taohua_feng");

	add_door("��������", "��������", "�һ���");
	add_door("�һ���Ĺ��", "�һ���Ĺ��", "�һ���");
	add_door("�һ���ɽ��", "�һ���ɽ��", "�һ���");
	add_door("�һ�ɽׯ����", "�һ�ɽׯ����", "�һ���");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp