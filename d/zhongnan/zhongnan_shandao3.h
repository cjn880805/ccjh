//shandao3.h

//Sample for room: ����ɽɽ��3
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shandao3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ��3");


	add_door("����ɽ����10", "����ɽ����10", "����ɽɽ��3");
	add_door("����ɽ̫�ҳ�", "����ɽ̫�ҳ�", "����ɽɽ��3");

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
