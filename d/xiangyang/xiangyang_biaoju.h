//biaoju.h

//Sample for room: �����ھ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_biaoju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����ھ�");

	//add npcs into the room
	add_npc("pub_biaotou");
				

	add_door("��������", "��������", "���������ھ�");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"eastroad1",
	]));
	set("objects", ([
		__DIR__"npc/biaotou" : 2,
	]));
********************************************/
};


ROOM_END;
