//hsyuan3.h

//Sample for room: ����Ժ����
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ����");
	set("sleep_room",1);

	add_npc("shaolin_hui_se");

	add_door("�����º���Ժ����", "�����º���Ժ����", "�����º���Ժ����");

	set("long", "������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣" );

/*****************************************************
	set("sleep_room",1);
	set("exits", ([
		"east" : __DIR__"zhulin2",
		"south" : __DIR__"hsyuan1",
		"north" : __DIR__"hsyuan3",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-xiu" : 1,
	]));
//	
********************************************/
};


ROOM_END;
