//chashi.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_chashi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");

	add_npc("shaolin_qing_le");

	add_door("�����·���¥", "�����·���¥", "�����²���");
	add_door("�����·�����", "�����·�����", "�����²���");

};


ROOM_END;
