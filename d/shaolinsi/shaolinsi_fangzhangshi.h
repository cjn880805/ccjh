//fangzhangshi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_fangzhangshi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	add_npc("shaolin_xuan_ci");

	add_door("�����²���", "�����²���", "�����·�����");

};


ROOM_END;
