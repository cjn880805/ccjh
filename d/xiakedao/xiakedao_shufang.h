//shufang.h

//Sample for room: ���͵��鷿
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵��鷿");

	//add npcs into the room
	add_npc("gaibang_shitianjing");
	add_npc("shaolin_daoseng");
	add_npc("pub_dizi");


	add_door("���͵�����", "���͵�����", "���͵��鷿");


/*****************************************************
  // �����ſڿ�����һ��С��(hole)��
        set("exits", ([
                "enter" : __DIR__"shihole1",
                "north" : __DIR__"xiuxis2",
                "east"  : __DIR__"shibi",
                "west"  : __DIR__"chashi",
        ]));

        set("objects", ([
                __DIR__"npc/shipotian" : 1,
                __DIR__"npc/daoseng": 1,
                __DIR__"npc/dizi": 2,
        ])); 
********************************************/
};


ROOM_END;
