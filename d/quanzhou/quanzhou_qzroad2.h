//qzroad2.h

//Sample for room: Ȫ��ɽ·2
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��ɽ·2");

	set("resident", "Ȫ��");
	
	add_npc("pub_playboy");        //add by zdn 2001-07-14


	add_door("Ȫ��ɽ·3", "Ȫ��ɽ·3", "Ȫ��ɽ·2");
	add_door("Ȫ��ɽ·1", "Ȫ��ɽ·1", "Ȫ��ɽ·2");
	add_door("���ݶ���", "���ݶ���", "Ȫ��ɽ·2");
	add_door("��������", "��������", "Ȫ��ɽ·2");	

	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qzroad2",
		"east" : __DIR__"qzroad4",
	]));

********************************************/
};


RESIDENT_END;
