//mtyadi.h

//Sample for room: ���͵��µ�
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_mtyadi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵��µ�");

	add_door("���͵�ɽ·", "���͵�ɽ·", "���͵��µ�");
	add_door("���͵�Ħ����", "���͵�Ħ����", "���͵��µ�");

    

/*****************************************************
        set("outdoors", "xiakedao");
        set("exits", ([
            "north" : __DIR__"mtroad",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp