//riyueyan.h

//Sample for room: ����ɽ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_riyueyan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ������");
	
	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("quanzhen_daotong");

	add_door("����ɽɽ·10", "����ɽɽ·10", "����ɽ������");
	add_door("����ɽɽ��9", "����ɽɽ��9", "����ɽ������");

	set("long","һ·������ֻ����ͺͺ��ɽ·���ԣ���ʯ��������Ϊ���ˡ�������ǰ����Զ���������ʯ����ߵ�һ�����������ұߵ��ǿ���̫�����е�����������һ������ֻ������һ����Լһ�˶��С��������ͨ���������ºͱ����߶���һ�����ѵ�ɽ·��" );

/*****************************************************
        set("exits", ([
                "eastdown"  : __DIR__"shanlu10",
                "northup"   : __DIR__"shanlu9",
        ]));
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
