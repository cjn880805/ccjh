//shijie6.h

//Sample for room: ����ɽʯ��6
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shijie6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��6");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_liumang");
	add_npc("pub_playboy");

	add_door("����ɽ�̱�", "����ɽ�̱�", "����ɽʯ��6");
	add_door("����ɽʯ��7", "����ɽʯ��7", "����ɽʯ��6");

	set("long","����һ�������ʯ��·����ɽ����������ɽ�Ƶ������������ۡ�����ɽ�ƶ��ˣ������޽�����ʯ��ʱ�϶����˲�С�Ĺ����ߵ�����Ѿ����Կ���ȫ��������۵��ܽ��ˡ�" );
    

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "northup" : __DIR__"shijie7",
                "southdown" : __DIR__"jiaobei",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
