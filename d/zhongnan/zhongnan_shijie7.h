//shijie7.h

//Sample for room: ����ɽʯ��7
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��7");

	add_npc("pub_youke2");
	add_npc("pub_manxiangke");

	add_door("����ɽʯ��6", "����ɽʯ��6", "����ɽʯ��7");
	add_door("����ɽ������", "����ɽ������", "����ɽʯ��7");

    set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );

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
