//riyuedong.h

//Sample for room: ���޺����¶�
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_riyuedong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���޺����¶�");
	add_npc("xingxiu_gushou");/////////////////////////
	add_npc("xingxiu_haoshou");
	add_npc("xingxiu_boshou");
        add_npc("xingxiu_ding");
        add_npc("xingxiu_tianlang");
	//add npcs into the room
	CBox * box1 = Add_Box();
	box1->add_object("bilinzhen", 10);	
	box1->set_name( "���");
		
	CBox * box2 = Add_Box();
	box2->add_object("lianxindan", 10);	
	box2->set_name( "���");
		
	CBox * box3 = Add_Box();
	box3->add_object("xxqingxin_san", 5);	
	box3->set_name( "���");	

	add_door("���޺�", "���޺�", "���޺����¶�");


/*****************************************************
         set("exits", ([
             "south" : __DIR__"xxh2",
        ]));

        set("item_desc", ([
                "zihua" : "����Щ�����������ɵ�ʫ�ʺ����Ļ���\n

����������������������������������
����������������������������������
�����������š������¡��ǡ���������
���������������䡡�ޡ���������
�����������ޡ�御��졡�ϡ���������
�����������ȡ���ء��ɡ���������
����������������������������������
����������������������������������
"
        ]) );

        set("objects", ([
                "/kungfu/class/xingxiu/ding" : 1,
                __DIR__"npc/obj/tiegun" : 1,
        ]) );
********************************************/
};


ROOM_END;
