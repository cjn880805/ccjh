//fu_datang.h

//Sample for room: ���Ҵ���
//coded by zouwenbin
//data: 2000-11-14

WUGONG_BEGIN(CRWuGong_fu_datang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҵ���");
//	add_npc("animal_wolfdog");

	add_door("�书����СԺ", "�书����СԺ", "�书���Ҵ���");


};


WUGONG_END;
