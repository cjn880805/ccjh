//hsyuan6.h

//Sample for room: ����Ժ����
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_hsyuan6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����Ժ����");

	set("sleep_room",1);

	add_npc("shaolin_hui_jie");

	add_door("�����º���Ժ�岿", "�����º���Ժ�岿", "�����º���Ժ����");
//	add_door("�����º���Ժ�Ĳ�", "�����º���Ժ�Ĳ�", "�����º���Ժ����");

	set("long", "������ɮ������ʳ��ӵĵط�����ǽһ����ż���ľ���������̵�����ϯ����ͷ���Ŵ�������������غ��䣬ɮ����ȫ����ʵ���ڹ�������������������ķ��ż������ź�ľ�㡣" );

/*****************************************************
	set("sleep_room",1);
	set("exits", ([
		"west" : __DIR__"zhulin6",
		"south" : __DIR__"hsyuan5",
	]));
	set("objects",([
		CLASS_D("shaolin") + "/hui-jie" : 1,
	]));
//	
********************************************/
};


ROOM_END;
