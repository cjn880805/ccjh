//xiaowu.h

//Sample for room:  ������С��
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_xiaowu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������С��");

	add_npc("shenlong_pang");
	add_npc("shenlong_shou");
	add_npc("shenlong_lu");

	add_door("�����̿յ�", "�����̿յ�", "������С��");

};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp