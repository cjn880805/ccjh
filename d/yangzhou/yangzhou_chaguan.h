//chaguan.h

//Sample for room: �������
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");

	//add npcs into the room
	add_npc("pub_aqingsao");/////////////////////////
	add_npc("wiz_redpacket");

	add_door("��������", "��������", "���ݴ������");

	set("no_fight",1);
	set("resource/water", 1);
/*****************************************************
	set("exits", ([
		"east" : __DIR__"nandajie2",
	]));
	set("objects", ([
		__DIR__"npc/aqingsao" : 1,
	]));
********************************************/
};


ROOM_END;




