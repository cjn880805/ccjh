//chufang.h

//Sample for room: ���������
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������");

	add_npc("pub_nanpu");

	add_door("������������", "������������", "���������");

};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp