//men2.h

//Sample for room: �����鷿����
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_men2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����鷿����");

	//add npcs into the room
	add_npc("lingjiu_nvlang");
	add_npc("lingjiu_zhujian");
	add_door("���ջ���12", "���ջ���12", "�����鷿����");

	

/*****************************************************
        set("outdoors", "lingjiu");
        set("exits", ([
		"east" : __DIR__"shufang",
		"west" : __DIR__"changl12",
        ]));
	set("objects",([
		__DIR__"npc/zhujian" : 1,
	]));
	set("item_desc", ([
	    "duilian" : "�е�ˮ�����������ʱ.\n",
	    "bian" : HIC "������ң\n" NOR,
        ]));
********************************************/
};


ROOM_END;
