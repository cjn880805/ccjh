//shijie1.h

//Sample for room: ����ɽʯ��1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��1");

	add_npc("pub_manxiangke");
	add_npc("pub_youke2");
	
	add_door("����ɽ��У��", "����ɽ��У��", "����ɽʯ��1");
	add_door("����ɽʯ��2", "����ɽʯ��2", "����ɽʯ��1");

    set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );
    

/*****************************************************
        set("exits", ([
                "northup"   : __DIR__"shijie2",
                "southdown" : "/d/gumu/daxiaochang",
        ]));

        set("objects",([
              __DIR__"npc/youke" : 1,
              __DIR__"npc/xiangke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
