//shijie4.h

//Sample for room: ����ɽʯ��4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��4");

	//add npcs into the room
	add_npc("pub_manxiangke");
	add_npc("pub_youke2");

				

	add_door("����ɽʯ��3", "����ɽʯ��3", "����ɽʯ��4");
	add_door("����ɽ�Խ���", "����ɽ�Խ���", "����ɽʯ��4");
	add_door("����ɽʯ��5", "����ɽʯ��5", "����ɽʯ��4");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie5",
                "westdown" : __DIR__"shijie3",
                "southup" : __DIR__"shijianyan",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 1,
        //      __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
