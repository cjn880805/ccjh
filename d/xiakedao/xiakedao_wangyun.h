//wangyun.h

//Sample for room: ���͵�����̨
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_wangyun);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�����̨");
	
	add_npc("xiakedao_shizhongyu");        //add by zdn 2001-07-20

	add_door("���͵�һ����", "���͵�һ����", "���͵�����̨");
    
//	add_npc("xiake_yanruoshui");

/*****************************************************
        set("exits", ([
                "northdown" : __DIR__"road8",
        ]));
        set("outdoors", "xiakedao" );
        set("item_desc",([
            "cao" : "������̵�С�ݣ��㲻������(take)������\n"
        ]) );
********************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp