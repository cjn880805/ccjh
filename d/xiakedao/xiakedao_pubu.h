//pubu.h

//Sample for room: ���͵��ٲ�
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_pubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵��ٲ�");
	
	add_npc("pub_jianke");        //add by zdn 2001-07-16

	add_door("���͵�ɽ·1", "���͵�ɽ·1", "���͵��ٲ�");
	add_door("���͵���", "���͵���", "���͵��ٲ�");

     

/*****************************************************
        set("exits", ([ 
                "northdown" : __DIR__"road4",
        ]));
        set("outdoors", "xiakedao");
        set("item_desc",([
            "pubu"   : "����ϸһ�����ٲ���������г��ڣ����ƺ�������(jump)��ȥ��\n",
            "xuanya" : "��������������ʲôҲ����������ɲ�Ҫ��(plump)��ȥѽ��\n",
        ]) );
********************************************/
};


ROOM_END;
//last, register the room into ../server/RoomSetup.cpp