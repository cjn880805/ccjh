//luohan1.h

//Sample for room: �޺���һ��
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�޺���һ��");

	add_npc("shaolin_cheng_guan");

	add_door("�����º��", "�����º��", "�������޺���һ��");
	add_door("�������޺��ö���", "�������޺��ö���", "�������޺���һ��");

	set("long", "����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ����书�����ڴ������" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"twtian",
		"north" : __DIR__"luohan2",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
********************************************/
};


ROOM_END;
