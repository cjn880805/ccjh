//shanlu7.h

//Sample for room: ����ɽɽ·7
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shanlu7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽɽ·7");
	
	//add npcs into the room 2001-07-10 zdn add 
	add_npc("pub_youke");
	add_npc("pub_xiangke");

	add_door("����ɽ��У��", "����ɽ��У��", "����ɽɽ·7");
	add_door("����ɽ������", "����ɽ������", "����ɽɽ·7");
	add_door("����ɽɽ��1", "����ɽɽ��1", "����ɽɽ·7");
	add_door("����ɽɽ·6", "����ɽɽ·6", "����ɽɽ·7");

	set("long","����һ���ǳ�������е�ɽ·��һ·������ɽ���ϣ���;���Ǵ����ĹŰ�ɽ�֣�εȻɭ�㡣�ڴ˴�����������ɽ�ľ�ɫ��ֻ��ɽ�������ɽ��ع�㣬���������֦ͷ�����䳪�������������ǲ����¡���������һ��ɽ·��������һ����Ŀյء�������ͨ����ɽ�¡�" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "westup"     : __DIR__"shanlu6",
                "northdown"  : __DIR__"caotangsi",
                "northwest"  : __DIR__"shandao1",
                "eastdown"   : __DIR__"daxiaochang",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
