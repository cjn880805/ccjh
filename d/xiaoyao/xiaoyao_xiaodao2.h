//xiaodao2.h

//Sample for room: С��2
//coded by zouwenbin
//data: 2000-11-17

/*
Edit by wolfman 2001-6-28
������ʱ����no_book�������ж������Ƿ��ѱ�������
*/

ROOM_BEGIN(CRXiaoYao_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ң��С��2");
	set_temp("no_book",1);

	add_npc("xiaoyao_goudu");
	add_npc("pub_likuozui");

	add_door("��ң��С��1", "��ң��С��1", "��ң��С��2");
	add_door("��ң��С��3", "��ң��С��3", "��ң��С��2");
	add_door("��ң��ľ��", "��ң��ľ��", "��ң��С��2");
	add_door("��ң��Сľ��", "��ң��Сľ��", "��ң��С��2");

/*****************************************************
	set("exits",([
		"north" : __DIR__"xiaodao2",
	]));
********************************************/
};


ROOM_END;
