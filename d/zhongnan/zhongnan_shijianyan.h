//shijianyan.h

//Sample for room: ����ɽ�Խ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijianyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�Խ���");

	add_npc("quanzhen_daotong");

	
	add_door("����ɽʯ��4", "����ɽʯ��4", "����ɽ�Խ���");
	add_door("����ɽ�̱�", "����ɽ�̱�", "����ɽ�Խ���");
	add_door("����ɽʯ��8", "����ɽʯ��8", "����ɽ�Խ���");


/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northdown" : __DIR__"shijie4",
                "southup" : __DIR__"shijie8",
                "east" : __DIR__"jiaobei",
        ]));
        set("objects",([
                __DIR__"npc/yin" : 1,
                __DIR__"npc/daotong" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
