//qfdian.h

//Sample for room: ǧ���
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_qfdian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ǧ���");

	add_npc("shaolin_qing_guan");

	add_door("����������", "����������", "������ǧ���");
	add_door("�����¹㳡", "�����¹㳡", "������ǧ���");

};


ROOM_END;
