//haitan.h

//Sample for room:  �����̺�̲
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_haitan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̺�̲");
	
	add_npc("pub_yufu");         //add by zdn 2001-07-15

	add_door("����������", "����������", "�����̺�̲");
	add_door("�����̹�ľ��", "�����̹�ľ��", "�����̺�̲");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp