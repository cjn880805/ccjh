//cuipinggu1.h

//Sample for room: ��ɽ������1
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRHengShan2_cuipinggu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ������1");

	//add npcs into the room
	add_npc("hengshan_yiwen");

	add_door("��ɽ����Ͽ", "��ɽ����Ͽ", "��ɽ������1");
	add_door("��ɽ������2", "��ɽ������2", "��ɽ������1");

    set("long","����ڹ��г�ˢ�����������ʹ���ɽ����Ͽ�����࣬����ǧ�����絶���������������ƣ������Թž�������ͨ���ڵص��ʺ�Ҫ��������һ�򵱹����Ī��֮�ơ� " );
	set("outdoors", "hengshan");

/*****************************************************
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		__DIR__"npc/wen" : 1,
	]));
********************************************/
};


ROOM_END;
