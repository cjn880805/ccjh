//dmyuan.h

//Sample for room: ��ĦԺ
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_dmyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ĦԺ");

	add_npc("shaolin_dao_yi");

	add_door("�����·���¥", "�����·���¥", "�����´�ĦԺ");
	add_door("�����´�ĦԺ��¥", "�����´�ĦԺ��¥", "�����´�ĦԺ");

	

/*****************************************************
	set("exits", ([
		"southdown" : __DIR__"wuchang3",
		"northdown" : __DIR__"guangchang5",
		"up"        : __DIR__"dmyuan2",
	]));

********************************************/
};


ROOM_END;
