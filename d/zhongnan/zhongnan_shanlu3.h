//shanlu3.h

//Sample for room: ����ɽɽ·3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·3");
	
	//add npcs into the room   2001=07-10 zdn add
	add_npc("quanzhen_daotong");

	add_door("����ɽɽ·2", "����ɽɽ·2", "����ɽɽ·3");
	add_door("����ɽ������", "����ɽ������", "����ɽɽ·3");

	set("long","������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫣���������ɽ��ɽ���ˡ�" );
    

/*****************************************************
        set("exits", ([
                "southwest" : __DIR__"shanlu2",
                "northup" : __DIR__"cuipinggu",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
