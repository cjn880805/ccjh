//juyiguan.h

//Sample for room: �����
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRXiangYang_juyiguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����");

	//add npcs into the room
	add_npc("dali_zhuziliu");/////////////////////////////////
				

	add_door("��������", "��������", "���������");

	set("outdoors", "xiangyang");
	
/*****************************************************
	set("exits", ([
		"east"  : __DIR__"juyilianwu1",
		"west"  : __DIR__"juyilianwu2",
		"south" : __DIR__"juyilang",
		"north" : __DIR__"westjie2",
	]));
	set("objects", ([
		__DIR__"npc/zhuziliu" : 1,
	]));
********************************************/
};


ROOM_END;
