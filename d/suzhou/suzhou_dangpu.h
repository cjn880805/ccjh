//dangpu.h

//Sample for room: ���ͼ�
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_dangpu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ͼ�");
	
	add_npc("pub_xiaoer2");         //add by zdn 2001-07-16


	add_door("������", "������", "���ݱ��ͼ�");

 	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	
/*****************************************************
	set("exits", ([
		"north"  : __DIR__"dongdajie1",
	]));
	set("item_desc", ([
		"sign" : "��ƽ����\n
sell        �� 
buy         ��
value       ����
",
	]));
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));

********************************************/
};


ROOM_END;
