//shanlu11.h

//Sample for room: ����ɽ��·11
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu11);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��·11");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_liumang");
	add_npc("pub_liumang");


	add_door("����ɽɽ·12", "����ɽɽ·12", "����ɽ��·11");
	add_door("����ɽ������", "����ɽ������", "����ɽ��·11");

	set("long","�˴�λ�����ɽɽ�š�Ρ�������ɽ���Թ�����������������������ʥ�ء������������ɽ���������������أ�����Խʮ���أ�����˰����������������ɽ֮�ơ������ɿ���һ������������һ��ͨ�����ֵ��ľ�С·��������������ɽ." );

/*****************************************************
        set("exits", ([
                "northup"   : __DIR__"shanlu12",
                "east"      : __DIR__"puguangsi",
                "west"      : __DIR__"shanlu14",
                "south"     : "/d/quanzhen/shanjiao",
        ]));
*****************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
