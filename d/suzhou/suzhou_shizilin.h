//shizilin.h

//Sample for room: ʨ����
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_shizilin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ʨ����");
	
	add_npc("animal_snake");        //add by zdn 2001-07-16

	add_npc("pub_qianwanguan"); 
	add_door("������", "������", "����ʨ����");
	add_door("����Ҿ��ָ����", "����Ҿ��ָ����", "����ʨ����");
	add_door("����������", "����������", "����ʨ����");
	
 	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"east"      : __DIR__"yanyutang",
		"west"      : __DIR__"nandajie1",
		"northeast" : __DIR__"zhipoxuan",
	]));

********************************************/
};


ROOM_END;
