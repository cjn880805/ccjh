//luohan3.h

//Sample for room: �޺�������
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�޺�������");

	add_npc("shaolin_cheng_ming");

	add_door("�������޺��ö���", "�������޺��ö���", "�������޺�������");
	add_door("�������޺����Ĳ�", "�������޺����Ĳ�", "�������޺�������");

	set("long", "����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ����书�����ڴ������" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"luohan2",
		"north" : __DIR__"luohan4",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
	//	
********************************************/
};


ROOM_END;
