//shanmen.h

//Sample for room: ɽ�ŵ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_shanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ɽ�ŵ�");

	add_npc("shaolin_xu_tong");
	add_npc("shaolin_xu_ming");

	add_door("������ʯ��", "������ʯ��", "������ɽ�ŵ�");
	add_door("������̨��", "������̨��", "������ɽ�ŵ�");

};


ROOM_END;
