//shanlu14.h

//Sample for room: ����ɽɽ��С��14
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu14);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��С��14");
	
	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");

	add_door("����ɽ��·13", "����ɽ��·13", "����ɽɽ��С��14");
	add_door("����ɽɽ��С��15", "����ɽɽ��С��15", "����ɽɽ��С��14");

	set("long","����һ��λ�����ɽ�ţ���Ϊ��֪��С�������ܹ�ľ���죬���ֲԴ䣬���ɽ����֦ͷ���񳪺Ͳ����������Ͷ��Ͽ�ͨ��ɽ�����" );

/*****************************************************
        set("exits", ([
                "east"      : __DIR__"shanlu13",
                "northwest" : __DIR__"shanlu15",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
