//shijie2.h

//Sample for room: ����ɽʯ��2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��2");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_youke2");
	add_npc("pub_xiangke");

	add_door("����ɽʯ��1", "����ɽʯ��1", "����ɽʯ��2");
	add_door("����ɽʯ��3", "����ɽʯ��3", "����ɽʯ��2");

	set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "southeast" : __DIR__"shijie3",
                "southdown" : __DIR__"shijie1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
