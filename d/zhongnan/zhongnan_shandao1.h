//shandao1.h

//Sample for room: ����ɽɽ��1
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shandao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��1");
	
	//add npcs into the room  2001-07-10 zdn add 
	add_npc("pub_youke2");

	add_door("����ɽɽ·7", "����ɽɽ·7", "����ɽɽ��1");
	add_door("����ɽɽ��2", "����ɽɽ��2", "����ɽɽ��1");

	set("long","�˶�ɽ·�������ͱڶ���������ģ��ر�������С���ʱ�ͱڱ߱�������ɽ赣�������������䵱ɽ�ﴵ��ʱ�������ر�С�ģ���Ȼһʧ�㣬��Ҫ����������Ԩ�ˡ���������һ����Ŀյء�������ͨ����ɽ�ţ�ԶԶ��������һ���ϴ�ĺ���" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southeast"   : __DIR__"shanlu7",
                "northdown"   : __DIR__"shandao2",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
