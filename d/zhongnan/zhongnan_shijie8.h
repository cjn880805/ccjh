//shijie8.h

//Sample for room: ����ɽʯ��8
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��8");

	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("����ɽ�Խ���", "����ɽ�Խ���", "����ɽʯ��8");
	add_door("����ɽ����̨", "����ɽ����̨", "����ɽʯ��8");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"fangzhenqiao",
                "southdown" : __DIR__"shijie6",
        ]));
        set("objects",([
              __DIR__"npc/youke" : 1,
              __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
