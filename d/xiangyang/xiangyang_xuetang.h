//xuetang.h

//Sample for room: ѧ��
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_xuetang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѧ��");

	//add npcs into the room
	add_npc("pub_laoxiansheng");/////////////////////////////
	add_npc("pub_huxiurong");

	add_door("��������", "��������", "����ѧ��");

/*****************************************************
	set("exits", ([
		"west" : __DIR__"southjie1",
	]));
	set("objects", ([
		__DIR__"npc/laoxiansheng" : 1,
	]));
********************************************/
};


ROOM_END;
