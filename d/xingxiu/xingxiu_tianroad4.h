//tianroad4.h

//Sample for room: ���޺���ɽɽ·4
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_tianroad4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺���ɽɽ·4");

	//add npcs into the room
	add_npc("pub_caiyaoren");
	add_npc("pub_xuemingfeng");
	
	CBox * box = Add_Box();
	box->add_object("xuelian", 1);	//put 100 coind into box
	box->set_name( "���");		//set
	
	add_door("���޺���ɽɽ·3", "���޺���ɽɽ·3", "���޺���ɽɽ·4");


/*****************************************************
         set("exits", ([
            "westup" : __DIR__"tianroad5"
        ]));
        set("objects", ([
                __DIR__"npc/caiyaoren"  : 1,
                __DIR__"npc/obj/xuelian" : 1
        ]));

        set("item_desc", ([
        "valley" : "������ɶ��������Ϊ��ߵ��Ƹߣ�Ӧ�ò�����(jump)��ȥ��\n"
        ]) );
********************************************/
};


ROOM_END;
