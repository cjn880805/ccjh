//lin.h

//Sample for room:  �����̹�ľ��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_lin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̹�ľ��");
	add_npc("animal_dushe");
	
	add_door("�����̺�̲", "�����̺�̲", "�����̹�ľ��");
	add_door("�����̿յ�", "�����̿յ�", "�����̹�ľ��");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp