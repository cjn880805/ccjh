//huanghai.h

//Sample for room:  �����ƺ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_huanghai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�");

	add_door("�����̺�̲", "�����̺�̲", "�����ƺ�");
	add_door("����������", "����������", "�����ƺ�");
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp