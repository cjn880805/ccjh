//xiaodao2.h

//Sample for room: ����С��2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRLingJiu_xiaodao2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С��2");


	add_npc("pub_cungu");

	add_door("����С��1", "����С��1", "����С��2");
	add_door("���ձչ��Ҵ���", "���ձչ��Ҵ���", "����С��2");

	set("long", "һ��С���������۵�ͨ��Զ��, �����������де����֣�΢�紵������Ҷ��������������" );

/*****************************************************
 	set("outdoors", "lingjiu");
        set("exits", ([
            "north" : __DIR__"men3",
            "south" : __DIR__"xiaodao1",
        ]));
        set("objects",([
            "/d/baituo/npc/cungu" : 2,
        ]));
********************************************/
};


ROOM_END;
