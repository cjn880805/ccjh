//shanlu2.h

//Sample for room: ����ɽɽ·2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·2");
	
	//add npcs into the room   2001-07-10  zdn add
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("����ɽɽ·3", "����ɽɽ·3", "����ɽɽ·2");
	add_door("����ɽɽ·1", "����ɽɽ·1", "����ɽɽ·2");
	add_door("����ɽ��ٵ�", "����ɽ��ٵ�", "����ɽɽ·2");

	set("long","һ��ɽ·����������ͨ��ɽ�ϡ������ɽ�Ϻ�����һƬ�����֣�����������¶��ͤ�ӵ�һ�ǣ����������ɽ��·��" );
    

/*****************************************************
        set("exits", ([
                "northeast" : __DIR__"shanlu3",
                "southeast" : __DIR__"shanlu4",
                "westdown" : __DIR__"shanlu1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
