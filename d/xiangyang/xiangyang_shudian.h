//shudian.h

//Sample for room: ���
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_shudian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���");

	//add npcs into the room
	add_npc("pub_shudianboss");
				

	add_door("��������", "��������", "�������");
/*****************************************************
	set("exits", ([
		"east" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/shudianboss" : 1,
	]));
********************************************/
};


ROOM_END;
