//shanlu8.h

//Sample for room: ����ɽɽ��8
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��8");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_liumangtou");
	add_npc("pub_liumang");
	add_npc("pub_liumang");

	add_door("����ɽ������", "����ɽ������", "����ɽɽ��8");
	add_door("����ɽ��У��", "����ɽ��У��", "����ɽɽ��8");

	set("long","�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱�������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬��Ҫ����������Ԩ�ˡ�������һ����Ŀյء���������һ����ҡ�" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"daxiaochang",
                "southdown"  : __DIR__"juyan",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
