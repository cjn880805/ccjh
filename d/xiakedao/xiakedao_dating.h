//dating.h

//Sample for room: ���͵�����
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_dating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�����");

	add_door("���͵�ʯ��2", "���͵�ʯ��2", "���͵�����");
	add_door("���͵��鷿", "���͵��鷿", "���͵�����");
	add_door("���͵�������", "���͵�������", "���͵�����");

    set("no_fight","1");

/*****************************************************
        set("item_desc",([
                "pingfeng" : "����һ������ʯ�������磬�ǳ�Ư����Ҳ���������ְ�����(push)����\n",
        ]));
        set("exits", ([
                "north" : __DIR__"shidong5",
                "east"  : __DIR__"shufang",
                "west"  : __DIR__"wuqiku",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 4,
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp