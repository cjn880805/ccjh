//shanlu15.h

//Sample for room: ����ɽɽ��С��15
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��С��15");

	//add npcs into the room 2001-07-10  zdn add
	add_npc("pub_liumang");

	add_door("����ɽɽ��С��14", "����ɽɽ��С��14", "����ɽɽ��С��15");
	add_door("����ɽɽ��С��16", "����ɽɽ��С��16", "����ɽɽ��С��15");

	set("long","����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ䣬���ɽ����֦ͷ���񳪺Ͳ����������Ͷ��Ͽ�ͨ��ɽ�����" );

/*****************************************************
        set("exits", ([
                "southeast" : __DIR__"shanlu14",
                "west"      : __DIR__"shanlu16",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
