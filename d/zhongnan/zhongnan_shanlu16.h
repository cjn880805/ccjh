//shanlu16.h

//Sample for room: ����ɽɽ��С��16
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu16);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��С��16");

	//add npcs into the room   2001-07-10 zdn add
	add_npc("animal_snake");

	add_door("����ɽɽ��С��15", "����ɽɽ��С��15", "����ɽɽ��С��16");
	add_door("����ɽС�ӱ�", "����ɽС�ӱ�", "����ɽɽ��С��16");

	set("long","����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ䣬���ɽ����֦ͷ���񳪺Ͳ��������Ͽɿ���һ��С�ӡ�������ͨ��ɽ�����" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "east"  : __DIR__"shanlu15",
                "south" : __DIR__"xiaohebian",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
