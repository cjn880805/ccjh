//luohan2.h

//Sample for room: �޺��ö���
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�޺��ö���");

	add_npc("shaolin_cheng_zhi");

	add_door("�������޺���һ��", "�������޺���һ��", "�������޺��ö���");
	add_door("�������޺�������", "�������޺�������", "�������޺��ö���");

	set("long", "����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ����书�����ڴ������" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"luohan1",
		"north" : __DIR__"luohan3",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
********************************************/
};


ROOM_END;