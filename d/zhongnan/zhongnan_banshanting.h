//banshanting.h

//Sample for room: ����ɽ��ɽͤ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_banshanting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��ɽͤ");
	

	add_npc("pub_youke");
	
	add_door("����ɽʯ��5", "����ɽʯ��5", "����ɽ��ɽͤ");

    set("long","�����ǰ�ɽ����һ��С��ͤ���ο�����ɽ�������ˣ���ת���䵽��������һ����ЪһЪ�š������￴��ȥ���պÿ��Կ���������ķ嶥��" );
    

/*****************************************************
        set("exits", ([
                "southdown" : __DIR__"shijie5",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
