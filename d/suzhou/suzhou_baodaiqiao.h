//baodaiqiao.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_baodaiqiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_seller");/////////////////////////

	add_door("����", "����", "���ݱ�����");

 	set("outdoors", "suzhou");
	
/*****************************************************
	set("exits", ([
		"northeast" : __DIR__"dongdajie1",
		"northwest" : __DIR__"xidajie1",
		"north"     : __DIR__"canlangting",
		"south"     : __DIR__"nandajie1",
	]));
	set("objects", ([
		__DIR__"npc/seller": 1,
	]));

********************************************/
};


ROOM_END;
