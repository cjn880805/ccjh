//stone_room.h

//Sample for room: ʯ��
//coded by zouwenbin
//data: 2000-11-18

ROOM_BEGIN(CRWanJie_stone_room);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ʯ��");


	add_door("��ٹ�С��", "��ٹ�С��", "��ٹ�ʯ��");
	add_npc("wanjie_foolmaster");

	set("no_fight", 1);


/*****************************************************
        set("exits", ([ 
            "south" : __DIR__"backyard",
        ]));
        set("objects", ([ 
            __DIR__"npc/mu" : 1,
        ]));
*****************************************************/
};


ROOM_END;
