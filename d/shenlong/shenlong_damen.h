//damen.h

//Sample for room:  �����̴���
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_damen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̴���");

	add_npc("zm_shenlong");

	add_door("�����̴��", "�����̴��", "�����̴���");
	add_door("�����̴���", "�����̴���", "�����̴���");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp