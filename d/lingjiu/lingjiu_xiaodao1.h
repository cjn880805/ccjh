//xiaodao1.h

//Sample for room: ����С��1
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xiaodao1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С��1");

	//add npcs into the room
	add_npc("pub_cungu");/////////////////////////

	add_door("���ջ�԰", "���ջ�԰", "����С��1");
	add_door("����С��2", "����С��2", "����С��1");

	set("long", "һ��С���������۵�ͨ��Զ��, �����������де����֣�΢�紵������Ҷ��������������" );

/*****************************************************
	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"xiaodao2",
            "south" : __DIR__"huayuan",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 1,
	]));
********************************************/
};


ROOM_END;
