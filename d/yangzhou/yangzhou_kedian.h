//kedian.h

//Sample for room: �͵�
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_kedian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�͵�");

	//add npcs into the room
	add_npc("pub_xiaoer2");/////////////////////////
				

	add_door("���ݶ���", "���ݶ���", "���ݿ͵�");
//	add_door("�������", "�������", "���ݿ͵�");

	set("no_fight", 1);
	set("valid_startroom", 1);
    set("sleep_room",1);
/*****************************************************
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"majiu",
		"west" : __DIR__"beidajie1",
		"up"   : __DIR__"kedian2",
	]));
********************************************/
};


ROOM_END;
