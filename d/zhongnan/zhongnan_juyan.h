//juyan.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_juyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	//add npcs into the room  2001-07-10 zdn add
	add_npc("pub_playboy");
	add_npc("pub_lady3");

	add_door("����ɽ����7", "����ɽ����7", "����ɽ������");
	add_door("����ɽɽ��8", "����ɽɽ��8", "����ɽ������");

	set("long","һ·������ɽ·��Խ��Խ�ա�ֻ��һ�����ʯ����·�У��Կ�ƾ�٣�����һ���ϸ��������ӣ�����״��ɭ�ɲ�������������η�������ο��ڴ�פ��ۿ���������һƬï�ܵ����֡���������һ�����͵�ɽ·��" );

/*****************************************************
        set("exits", ([
                "northup"    : __DIR__"shanlu8",
                "southdown"  : __DIR__"shulin7",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/ji": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
