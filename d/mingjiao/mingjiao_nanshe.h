//nanshe.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_nanshe);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");

	add_door("�������Ź㳡", "�������Ź㳡", "������������");
	add_npc("mingjiao_tianmen");

    
    set("sleep_room", 1);
    set("no_fight", 1);

/*****************************************************
     set("exits", ([
        "out" : __DIR__"mjtianmen1",
    ]));

********************************************/
};


ROOM_END;
