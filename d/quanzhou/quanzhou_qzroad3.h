//qzroad3.h

//Sample for room: Ȫ��ɽ·3
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_qzroad3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��ɽ·3");

	set("resident", "Ȫ��");
	
	add_npc("pub_cunfu");      //add by zdn 2001-07-14


	add_door("Ȫ��ɽ·4", "Ȫ��ɽ·4", "Ȫ��ɽ·3");
	add_door("Ȫ��ɽ·2", "Ȫ��ɽ·2", "Ȫ��ɽ·3");
	add_door("������ʯ���1", "������ʯ���1", "Ȫ��ɽ·3");
		
	
	
/*****************************************************
	set("exits", ([
		"north" : __DIR__"qzroad2",
		"east" : __DIR__"qzroad4",
	]));

********************************************/
};


RESIDENT_END;
