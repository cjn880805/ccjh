//datiepu.h

//Sample for room: ������
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_datiepu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_smith");/////////////////////////

	add_door("������", "������", "���ݴ�����");

 	set("outdoors", "suzhou");
/*****************************************************
	set("exits", ([
		"north" : __DIR__"dongdajie2",
	]));
        set("objects", ([
		"/d/city/npc/smith": 1,
	]));

********************************************/
};


ROOM_END;
