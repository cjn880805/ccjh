//wofang.h

//Sample for room: �Է�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRTaoHua_wofang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�Է�");

	//add npcs into the room
	add_npc("taohuadao_binu");
	add_npc("taohua_rong");

	add_door("�һ���ɽׯ����", "�һ���ɽׯ����", "�һ����Է�");
	add_door("�һ�ɽׯ�鷿", "�һ�ɽׯ�鷿", "�һ����Է�");


	set("sleep_room", 1);
/*****************************************************
    set("exits", ([
        "east" :__DIR__"dating",
    ]));
    set("objects", ([
        CLASS_D("taohua")+"/rong" : 1,
        __DIR__"npc/binu" : 2,
    ]) );
********************************************/
};


ROOM_END;
