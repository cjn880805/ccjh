//shanlu4.h

//Sample for room: ����ɽɽ·4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·4");

	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_seller");

	add_door("����ɽɽ·5", "����ɽɽ·5", "����ɽɽ·4");
	add_door("��Ĺ����ɽ����", "��Ĺ����ɽ����", "����ɽɽ·4");

	set("long","������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫣���������ɽ��ɽ���ˡ�" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "eastup" : __DIR__"shanjiao",
//                "southwest" : "/d/gumu/shulin1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
