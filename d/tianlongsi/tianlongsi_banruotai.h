//banruotai.h

//Sample for room:  �����°���̨
//coded by zouwenbin
//data: 2000-11-30

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRTianLongSi_banruotai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����°���̨");

	add_door("�����¶��ʴ�ʿԺ", "�����¶��ʴ�ʿԺ", "�����°���̨");
	add_door("������Ĳ����", "������Ĳ����", "�����°���̨");

	set("long","���Ǹ���ͨ��ʯ̨���ഫ������������ٴ�̨������������ȥ���Ǳ����صء���Ĳ���á������д��������µ�����֮�������������׾Ͳ��ڴ��У�����ǧ��Ҫ��ʲô���⡣");
    

/******************************************************************************
	set("exits", ([
		"south" : __DIR__"munitang",
		"north" : __DIR__"doushuai",
	]));
******************************************************************************/
};


ROOM_END;
