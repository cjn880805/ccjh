//erxianting.h

//Sample for room: ����ͤ
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_erxianting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ͤ");
	
	add_npc("pub_flowerg");       //add by zdn 2001-07-16
	add_npc("helpnpc009");


	add_door("���ݰ�����", "���ݰ�����", "���ݶ���ͤ");
	add_door("����ǧ��ʯ", "����ǧ��ʯ", "���ݶ���ͤ");

	

/*****************************************************
	set("outdoors", "suzhou");
	set("exits", ([
		"west"  : __DIR__"qianrenshi",
		"north" : __DIR__"bailianchi",
	]));
********************************************/
};


ROOM_END;
