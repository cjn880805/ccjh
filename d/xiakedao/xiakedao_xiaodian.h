//xiaodian.h

//Sample for room: ���͵�С�Ե�
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_xiaodian);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���͵�С�Ե�");
	add_npc("pub_xiaoer2");

	add_door("���͵�ӭ����", "���͵�ӭ����", "���͵�С�Ե�");

	

/*****************************************************
         set("exits", ([
                "west" : __DIR__"yingbin",
        ]));
        set("objects", ([
                __DIR__"npc/xiaoer2" : 1,
        ]));
        
********************************************/
};


ROOM_END;
