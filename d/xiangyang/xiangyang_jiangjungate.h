//jiangjungate.h

//Sample for room: ����������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_jiangjungate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("xiangyang_guojing");        //add by zdn 2001-07-20
	add_npc("helpnpc001");


	add_door("��������", "��������", "��������������");

	set("outdoors", "xiangyang");
/*****************************************************
	set("exits", ([
		"south" : __DIR__"eastjie1",
		"north" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
********************************************/
};


ROOM_END;
