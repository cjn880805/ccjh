//qcroad1.h

//Sample for room: �����ʯ���
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRQingCheng_qcroad1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ʯ���");
	
	add_npc("pub_playboy");
	add_npc("pub_daoke");         //add by zdn 2001-07-14


	add_door("���С��", "���С��", "�����ʯ���");
	add_door("�ɶ�������", "�ɶ�������", "�����ʯ���");


    

/*****************************************************
    set("outdoors","qingcheng");
	set("exits", ([
		"south" : "/d/city3/fuheqiaon",
		"west"  : __DIR__"qcroad2",
	]));
*****************************************************/
};


ROOM_END;
