//shanlu13.h

//Sample for room: ����ɽ��·13
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu13);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��·13");

	//add npcs into the room  2001-07-10 zdn add 
	add_npc("pub_youke2");

	add_door("����ɽ��", "����ɽ��", "����ɽ��·13");
	add_door("����ɽɽ·12", "����ɽɽ·12", "����ɽ��·13");
	add_door("����ɽ�չ���", "����ɽ�չ���", "����ɽ��·13");
	add_door("����ɽɽ��С��14", "����ɽɽ��С��14", "����ɽ��·13");

	set("long","�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�����������������������ʥ�ء������������ɽ���������������أ�����Խʮ���أ�����˰����������������ɽ֮�ơ������ɿ���һ������������һ��ͨ�����ֵ��ľ�С·��������������ɽ." );

/*****************************************************
        set("exits", ([
                "northup"   : __DIR__"shanlu12",
                "east"      : __DIR__"puguangsi",
                "west"      : __DIR__"shanlu14",
                "south"     : "/d/quanzhen/shanjiao",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
