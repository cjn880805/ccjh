//baoziyan.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baoziyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_jianke");
	add_npc("quanzhen_daotong");

	add_door("����ɽ����9", "����ɽ����9", "����ɽ������");
	add_door("����ɽ����8", "����ɽ����8", "����ɽ������");

	set("long","һ·������ɽ·��Խ��Խ�ա�ֻ����ͺͺ��ɽ·�����Ծ��ǹ�ʯ����������������Ԩ���첻���ס�ǰ����Զ����һ���ʯ�����������ı����ҡ��ٿ����ۣ�����������������֣�����һ�����˱��Ÿ����Ӱ㣬ϸ�ĺǻ������Ϻ�������һƬ���֡�" );

/*****************************************************
        set("exits", ([
                "west"      : __DIR__"shulin8",
                "south"     : __DIR__"shulin9",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/chen": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
