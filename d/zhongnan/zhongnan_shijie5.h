//shijie5.h

//Sample for room: ����ɽʯ��5
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��5");

	//add npcs into the room   2001=07-10 zdn add
	add_npc("quanzhen_daotong");
	add_npc("pub_youke");

	add_door("����ɽʯ��4", "����ɽʯ��4", "����ɽʯ��5");
	add_door("����ɽ��ɽͤ", "����ɽ��ɽͤ", "����ɽʯ��5");

	set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"banshanting",
                "southdown" : __DIR__"shijie4",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
