//xiaoyao.h

//Sample for room: ���޺���ң��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_xiaoyao);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺���ң��");

	add_door("���޺�ʯ��", "���޺�ʯ��", "���޺���ң��");

    
    add_npc("xingxiu_azi");
    add_npc("zm_xingxiu");
    add_npc("xingxiu_shihou");
    set("sleep_room", 1);

/*****************************************************
        set("exits", ([
                "out" : __DIR__"xxh6",
        ]));
        set("item_desc", ([
                "wall" : "�����������˵ö���֮��\n",
        ]) );
********************************************/
};


ROOM_END;
