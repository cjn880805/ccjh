//duchang.h

//Sample for room: �ĳ�
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_duchang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ĳ�");

	//add npcs into the room
	add_npc("pub_xianren");        //add by zdn 2001-07-16
	
	add_door("��������", "��������", "���ݶĳ�");

	set("long", "�����Ƕĳ��Ĵ��ã����ܵķ����ﴫ����ߺ������ĶĲ����������Ƕġ���С���ķ��䣬�����Ƕġ��ƾš��ķ���(������)���������������еĲ������ּ䡣ǽ�����۴�����һ������(paizi)��" );
	
/*****************************************************
	set("item_desc", ([
		"paizi" : "��¥�Ĺ��������ڲ��Խ׶Ρ�\n",
	]));
	set("objects", ([
		CLASS_D("shenlong")+"/pang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"daxiao",
		"up"   : __DIR__"duchang2",
		"east" : __DIR__"nandajie1",
		"south": __DIR__"bobing",
	]));
********************************************/
};


ROOM_END;
