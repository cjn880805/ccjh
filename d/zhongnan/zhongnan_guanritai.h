//guanritai.h

//Sample for room: ����ɽ����̨
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_guanritai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����̨");

	//add npcs into the room
	add_npc("pub_youke");/////////////////////////
	add_npc("pub_xiangke");

				
	
	add_door("����ɽʯ��8", "����ɽʯ��8", "����ɽ����̨");

    set("long","����������ɽ�ϵĹ���̨����֪�ĳ��Ĵ��������������������ƽ̨��������հ�ճ��������������ɽ�Ʒǳ�����������һ�������±��������°���Ʈ�����治֪���ںξ���" );

/*****************************************************
        set("outdoors", "quanzhen");
        set("exits", ([
                "north" : __DIR__"shijie9",
        ]));
        set("objects",([
                __DIR__"npc/youke" : 1,
                __DIR__"npc/xiangke" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
