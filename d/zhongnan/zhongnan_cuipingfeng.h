//cuipingfeng.h

//Sample for room: ����ɽ�����嶥
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_cuipingfeng);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�����嶥");

	//add npcs into the room
	add_npc("pub_youke");
	add_npc("pub_playboy");   //2001-07-10 zdn add

	add_door("����ɽ������", "����ɽ������", "����ɽ�����嶥");


/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"baishulin3",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
