//damenkan.h

//Sample for room: ���ſ���
//coded by zouwenbin
//data: 2000-12-1

RESIDENT_BEGIN(CRGuanWai_damenkan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ſ���");
	
	set("resident", "����");


	add_npc("guanwai_yanji");      //add by zdn 2001-07-20

	add_door("�������", "�������", "������ſ���");
	add_door("������ſ���", "������ſ���", "������ſ���");

    set("long","�������ؽ��򶫵Ĺŵ�����Ϊ��ɽ�ɲεĲο����ߣ����Ҳ�ơ���·����ǰ��һ��Сɽ�ض�ȥ·�����������ſ�����Ϊ��ȥ�ɲεĵ�һ�����ϣ��ʱ���Ϊ���ſ��ӡ������ǿ������ɻ������ɻ����ڶ���ʱ�����ͨ�У����ﻯ����ֻ���Ҵ��Ұ�æ�ˡ�" );
    

/*****************************************************
	set("exits", ([
		"northeast"  : __DIR__"ermenkan",
		"west"       : __DIR__"bingmian",
	]));
********************************************/
};


RESIDENT_END;
