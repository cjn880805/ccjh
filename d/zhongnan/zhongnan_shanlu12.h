//shanlu12.h

//Sample for room: ����ɽɽ·12
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·12");

	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("����ɽ��·13", "����ɽ��·13", "����ɽɽ·12");
	add_door("����ɽ��·11", "����ɽ��·11", "����ɽɽ·12");

	set("long","����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ����ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��ع�㣬��������һ����·������������һ�����ѵ�ɽ·��" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"   : __DIR__"shanlu11",
                "southdown" : __DIR__"shanlu13",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
