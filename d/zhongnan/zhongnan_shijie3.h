//shijie3.h

//Sample for room: ����ɽʯ��3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��3");

	add_npc("pub_manxiangke");
	add_npc("pub_youke2");
	
	add_door("����ɽʯ��2", "����ɽʯ��2", "����ɽʯ��3");
	add_door("����ɽʯ��4", "����ɽʯ��4", "����ɽʯ��3");

    set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"shijie2",
                "eastup" : __DIR__"shijie4",
        ]));
        set("objects",([
        //      __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
