//shenheyuan.h

//Sample for room: ����ɽ���ԭ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shenheyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ���ԭ");

	add_npc("pub_seller");

	
	add_door("����ɽ����8", "����ɽ����8", "����ɽ���ԭ");
	add_door("����ɽ����7", "����ɽ����7", "����ɽ���ԭ");
	add_door("����ɽ��ү��", "����ɽ��ү��", "����ɽ���ԭ");

    set("long","�˴�λ�����ɽ�в��Ĵ仪ɽ������������ȥ��ֻ��һƬ̹������Ĵ�ƽԭ������Ⱥɽ֮�䡣��˵�̳�ĩ�꣬�������ʱ��������򳤰�ʱ�����ݶ�ȱ���ڴ˻�����Ϻ�֮���������������������Ϊ���ԭ�������Ϻͱ��ϸ���һƬ���֡�������һ���ż���" );

/*****************************************************
        set("exits", ([
                "west"      : __DIR__"foyezhang",
                "north"     : __DIR__"shulin7",
                "southeast" : __DIR__"shulin8",
        ]));
        set("objects", ([
                "/d/quanzhen/npc/seller": 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
