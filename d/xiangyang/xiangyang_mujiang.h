//mujiang.h

//Sample for room: ľ����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_mujiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ľ����");

	//add npcs into the room
	add_npc("pub_mujiang");
	add_npc("pub_kangzhongming");
				
	add_door("��������", "��������", "����ľ����");
/*****************************************************
	set("exits", ([
		"north" : __DIR__"eastjie3",
	]));
	set("objects", ([
		__DIR__"npc/mujiang" : 1,
	]));
********************************************/
};


ROOM_END;
