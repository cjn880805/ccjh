//tianxiang.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_tianxiang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");
	
	add_npc("heimuya_shang");     //add by zdn 2001-07-20


	add_door("��ľ�������ô���", "��ľ�������ô���", "��ľ��������");

	set("long", "�����Ǻ�ľ�µĵ��Ĵ��á������á���һ���긾�˺�ü���ڵ��ء�");

/*****************************************************
        set("exits", ([
            "northdown"   : __DIR__"dating4",
        ]));
        set("objects", ([
            __DIR__"npc/shang" : 1,
        ]));       
//        
********************************************/
};



ROOM_END;
//last, register the room into ../server/RoomSetup.cpp