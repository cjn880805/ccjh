//dating.h

//Sample for room:  �����̴���
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����̴���");

	add_npc("shenlong_yin");
	add_npc("shenlong_hong");
	add_npc("shenlong_wugeng");

	add_door("�����̴���", "�����̴���", "�����̴���");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp