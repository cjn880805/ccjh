//heifengdong.h

//Sample for room: ����ɽ�ڷﶴ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_heifengdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ�ڷﶴ");
	
	add_npc("pub_youke2");
	add_npc("pub_lady3");   //2001-07-10 zdn add

	add_door("����ɽ����7", "����ɽ����7", "����ɽ�ڷﶴ");

	set("long","�˴�λ�����ɽ��������̫��ɽ�ϡ�ֻ��ɽ��ֱ��ֱ�£����а�Ķ��ͣ�ֻɽ������һ�������Ӵֵ�ʯ������ʱð��һ�ɺ������ֿ��µġ�������һƬ���֡�" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "westup"  : __DIR__"shulin7",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
