//dongmen.h

//Sample for room: ���ݶ���
//coded by Fisho
//data: 2000-11-3

ROOM_BEGIN(CRSuZhou_dongmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ݶ���");

	//add npcs into the room
	add_npc("pub_wujiang");/////////////////////////
	add_npc("pub_bing");

	add_npc("pub_playboy");
	add_npc("pub_tiezhan");

	add_door("������", "������", "���ݶ���");
	add_door("Ȫ��ɽ·2", "Ȫ��ɽ·2", "���ݶ���");


/*****************************************************
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : "/d/quanzhou/qzroad2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
********************************************/
};


ROOM_END;
