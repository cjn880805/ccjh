//banruo1.h

//Sample for room: ������һ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_banruo1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������һ��");

	add_npc("shaolin_cheng_xin");

	add_door("�����º��", "�����º��", "�����°�����һ��");
	add_door("�����°����ö���", "�����°����ö���", "�����°�����һ��");


/*****************************************************
	set("exits", ([
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"banruo2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
//	
********************************************/
};


ROOM_END;
