//shidong7.h

//Sample for room: ���͵�ʯ��7
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ʯ��7");
	
	add_npc("wudang_zhangsan");        //add by zdn 2001-07-20


	add_door("���͵�ʯ��6", "���͵�ʯ��6", "���͵�ʯ��7");
	add_door("���͵�ʯ��8", "���͵�ʯ��8", "���͵�ʯ��7");

    set("long", "����һ��ʯ���������ǹ⻬��ʯ�ڣ����ڸɸɾ�����һ����Ⱦȴ����һ�ˣ�������Χ�е����ѣ���ʯ����ҫ�����Ƿ���" );
    

/*****************************************************
        set("exits", ([
                "west" : __DIR__"shidong8",
                "north" : __DIR__"shidong6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp