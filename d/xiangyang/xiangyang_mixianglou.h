//mixianglou.h

//Sample for room: ����¥
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_mixianglou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����¥");

	//add npcs into the room
	add_npc("pub_xiaoer2");
				

	add_door("��������", "��������", "��������¥");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"southjie2",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
********************************************/
};


ROOM_END;
