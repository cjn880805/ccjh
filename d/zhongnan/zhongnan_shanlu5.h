//shanlu5.h

//Sample for room: ����ɽɽ·5
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·5");

	add_npc("pub_lishenping");
	add_door("����ɽɽ·6", "����ɽɽ·6", "����ɽɽ·5");
	add_door("����ɽɽ·4", "����ɽɽ·4", "����ɽɽ·5");

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
