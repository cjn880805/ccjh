//road7.h

//Sample for room: ���͵��б�ʯ
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵��б�ʯ");
	
	add_npc("gaibang_shitianjing");        //add by zdn 2001-07-20


	add_door("���͵�ɽ·6", "���͵�ɽ·6", "���͵��б�ʯ");
	add_door("���͵�һ����", "���͵�һ����", "���͵��б�ʯ");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
                "southup"   : __DIR__"road8",
                "northdown" : __DIR__"road6",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp