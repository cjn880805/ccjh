//shidong6.h

//Sample for room: ���͵�ʯ��6
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_shidong6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�ʯ��7");
	
	add_npc("baituo_xieyan");        //add by zdn 2001-07-20


	add_door("���͵�ʯ��1", "���͵�ʯ��1", "���͵�ʯ��6");
	add_door("���͵�ʯ��7", "���͵�ʯ��7", "���͵�ʯ��6");

    set("long", "����һ��ʯ����������խ���������˲������������Ҳ���ǵͰ������ֱ�ɴ������͵ƻζ��������������������Ӱ���Ų����ʯ���˶���������������о���Щ������" );
    

/*****************************************************
        set("exits", ([
                "south" : __DIR__"shidong7",
                "north" : __DIR__"shidong1",
        ]));
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp