//luohan4.h

//Sample for room: �޺����Ĳ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan4);

virtual void create()			//Call it when Room Create
{
	set_name( "�޺����Ĳ�");

	add_npc("shaolin_cheng_jing");

	add_door("�������޺�������", "�������޺�������", "�������޺����Ĳ�");
	add_door("�������޺����岿", "�������޺����岿", "�������޺����Ĳ�");

};


ROOM_END;
