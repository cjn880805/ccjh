//chufang.h

//Sample for room: ����
//coded by zouwenbin
//data: 2000-11-14

ROOM_BEGIN(CRShaoLinSi_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����");


	add_door("������ի��", "������ի��", "�����³���");

	set("long", "�������ƣ��������ڣ���ζ�˱Ƕ�������ǽ��һ�����ɳ�����̨��֧��ʮ���ڴ��������һ�ڷ����Ϸ������˴��������ն��£��ֳ�ľ���ڽ��衣�����շ���ɮ���⣬��λ��ͷ��æ��������н������¯�����ܡ�һλ����ɮ�������شߴ��š�" );

/*****************************************************
	set("exits", ([
		"south" : __DIR__"fanting1",
	]));
	set("objects",([
		__DIR__"npc/shaofan-seng" : 2,
	]));
//	
********************************************/
};


ROOM_END;
