//lianwu.h

//Sample for room: ���������䳡
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_lianwu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������䳡");

	add_npc("shaolin_dao_cheng");
	add_npc("shaolin_dao_jue");

	add_door("�����º��", "�����º��", "���������䳡");
	add_door("�����°������岿", "�����°������岿", "���������䳡");
	add_door("�������޺����岿", "�������޺����岿", "���������䳡");
	add_door("�����·���¥", "�����·���¥", "���������䳡");

};

ROOM_END;
