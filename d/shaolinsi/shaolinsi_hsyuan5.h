//hsyuan5.h

//Sample for room: ����Ժ�岿
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ�岿");
	set("sleep_room",1);

	add_npc("shaolin_hui_ming");

	add_door("�����º���Ժ�Ĳ�", "�����º���Ժ�Ĳ�", "�����º���Ժ�岿");
	add_door("�����º���Ժ����", "�����º���Ժ����", "�����º���Ժ�岿");

	set("long", "������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣" );

/*****************************************************
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"zhulin5",
		"south" : __DIR__"hsyuan4",
		"north" : __DIR__"hsyuan6",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-ming" : 1,
	]));
//	
********************************************/
};


ROOM_END;
