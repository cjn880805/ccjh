//shulin10.h

//Sample for room: ����ɽ����10
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRZhongNan_shulin10);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ����10");

	//add npcs into the room 2001-07-10 zdn add
	add_npc("pub_daoke");
	add_npc("pub_liumangtou");


	add_door("����ɽɽ��2", "����ɽɽ��2", "����ɽ����10");
	add_door("����ɽɽ��3", "����ɽɽ��3", "����ɽ����10");

	set("long","��λ�����ɽ���һ��Ƭ���֣�������Ϊï�ܡ�������䣬ֻ���ý���ɳɳ����Ҷ�������ܻ�谵���ģ���ʱ�����չ⴩��Ũ�ܵ�֦ͷ��Ͷ����¡�ż��Զ�������޺�����������һ�����ܸС��������ϸ���һ��С����" );

/*****************************************************
        set("outdoors", "gumu");
        set("exits", ([
                "southup"   : __DIR__"shandao2",
                "north"     : __DIR__"shulin11",
        ]));
        set("objects", ([
                "/d/wudang/npc/bee" : 1,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp
