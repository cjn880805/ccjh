//shanlu6.h

//Sample for room: ����ɽɽ·6
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·6");

	//add npcs into the room  2001-07-10 zdn add
	add_npc("quanzhen_daotong");

	add_door("����ɽɽ·7", "����ɽɽ·7", "����ɽɽ·6");
	add_door("����ɽɽ·5", "����ɽɽ·5", "����ɽɽ·6");
	add_door("����ɽ����̶", "����ɽ����̶", "����ɽɽ·6");

	set("long","����ɽ·������ɽ������ϣ�ɽ·����ʯ������ֻ��һ�˿ɹ������Ƽ�Ϊ�վ�����Զ����ȥ��Ⱥɽ���ƣ���춽��£��������������۵ף���ʱ���˺�����������Ҫ��Хһ���������ºͱ��ϸ���һ��ɽ·���������ǰ���̶��" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup"    : __DIR__"shanlu5",
                "eastdown"   : __DIR__"shanlu7",
                "southdown"  : __DIR__"baimatang",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
