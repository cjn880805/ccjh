//path1.h

//Sample for room: �����ɽ���
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_path1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ɽ���");
	
	add_npc("qingcheng_hong");      //add by zdn 2001-07-14


	add_door("����̽�����", "����̽�����", "�����ɽ���");
	add_door("�����Ȼͼ��", "�����Ȼͼ��", "�����ɽ���");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"southeast" : __DIR__"jianfugong",
		"westup"    : __DIR__"tianran",
	]));
*****************************************************/
};


ROOM_END;
