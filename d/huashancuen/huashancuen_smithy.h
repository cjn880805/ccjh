//smithy.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRHuaShanCuen_smithy);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("pub_tiejiang");

	add_door("��ɽ��", "��ɽ��", "��ɽ��������");

/*****************************************************
        set("exits", ([ 
            "east" : __DIR__"smithy2",
            "north" : __DIR__"eroad3",
        ]));
//        
        set("objects", ([
             __DIR__"npc/smith": 1
        ]) );
********************************************/
};


ROOM_END;
