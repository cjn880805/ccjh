//shanjiao.h

//Sample for room: ����ɽ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanjiao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��");

	//add npcs into the room
	add_npc("pub_youke");/////////////////////////
	add_npc("pub_xiangke");

				

	add_door("����ɽɽ·1", "����ɽɽ·1", "����ɽ��");
	add_door("����ɽ��·13", "����ɽ��·13", "����ɽ��");


/*****************************************************
        set("exits", ([
//                "northup" : __DIR__"shijie1",
                "north"    : "/d/gumu/shanlu13",
                "westdown" : __DIR__"shanlu4",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
