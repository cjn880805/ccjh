//shandao2.h

//Sample for room: ����ɽɽ��2
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shandao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��2");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("pub_liumangtou");

	add_door("����ɽɽ��1", "����ɽɽ��1", "����ɽɽ��2");
	add_door("����ɽ����10", "����ɽ����10", "����ɽɽ��2");

	set("long","�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱�������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬��Ҫ����������Ԩ�ˡ���������һ����Ŀյء�������ͨ����ɽ�ţ�ԶԶ��������һ���ϴ�ĺ���" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shandao1",
                "northdown" : __DIR__"shulin10",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
