//baimatang.h

//Sample for room: ����ɽ����̶
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_baimatang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����̶");

	//add npcs into the room    20001-07-10 zdn add
	add_npc("pub_huanu");
	add_npc("pub_lady3");

	add_door("����ɽɽ·6", "����ɽɽ·6", "����ɽ����̶");

    set("long","���̶Ϊ�����ɽ����һ����һ�����п����ӵ����Ρ�̶����һ������䷿�ӻ�Ҫ��İ�ʯͷ����ʯͷ�м����ͷ�ߣ�ʯͷ��ǰ�������ˮ��������ڰ��ϡ�������ˮ�е��ǰ��ʯͷ���滹��ʱð��һ������ĭ����Զ��ȥ����һƥ�ڿ����ɵ�������˵����˶��д�̶Ϊ����̶��������һ����᫵�ɽ·��" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "northup" : __DIR__"shanlu6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp