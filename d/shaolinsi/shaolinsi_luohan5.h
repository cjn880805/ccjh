//luohan5.h

//Sample for room: �޺����岿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�޺����岿");

	add_npc("shaolin_cheng_jian");
	add_npc("shaolin_xuan_ku");

	add_door("���������䳡", "���������䳡", "�������޺����岿");
	add_door("�������޺����Ĳ�", "�������޺����Ĳ�", "�������޺����岿");
	add_door("�������޺�������", "�������޺�������", "�������޺����岿");

};


ROOM_END;
