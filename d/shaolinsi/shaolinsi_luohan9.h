//luohan9.h

//Sample for room: �޺��þŲ�
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_luohan9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�޺��þŲ�");

	add_npc("shaolin_cheng_he");

	add_door("�������޺��ð˲�", "�������޺��ð˲�", "�������޺��þŲ�");
	add_door("�����·���¥", "�����·���¥", "�������޺��þŲ�");

	set("long", "����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ����ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ�뷢���׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������еĵط������پ����书�����ڴ������" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"louhan8",
		"north" : __DIR__"fzlou",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/cheng-xin" : 1,
	]));
//	
********************************************/
};


ROOM_END;
