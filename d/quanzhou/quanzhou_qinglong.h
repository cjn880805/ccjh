//qinglong.h

//Sample for room: Ȫ��������ǰͥ
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRQuanZhou_qinglong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ��������ǰͥ");

	add_npc("pub_wuweiyang");
	add_door("Ȫ������С��", "Ȫ������С��", "Ȫ��������ǰͥ");
	add_door("Ȫ���������ͥ3", "Ȫ���������ͥ3", "Ȫ��������ǰͥ");
	add_door("Ȫ���������ͥ2", "Ȫ���������ͥ2", "Ȫ��������ǰͥ");
	add_door("Ȫ���������ͥ", "Ȫ���������ͥ", "Ȫ��������ǰͥ");

	
	
/*****************************************************
	set("exits", ([
		"west"  : __DIR__"qinglong1",
		"south" : __DIR__"qinglong2",
		"north" : __DIR__"qinglong3",
		"east"  : __DIR__"bamboo",
	]));
//	set("objects",([
//		__DIR__"npc/tang" : 1,
//	]));
	create_door("east","ľ��","west",DOOR_CLOSED);
********************************************/
};


ROOM_END;
