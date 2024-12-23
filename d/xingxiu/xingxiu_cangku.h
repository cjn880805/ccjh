//cangku.h

//Sample for room: ÐÇËÞÅÉ´¢²ØÊÒ
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXingXiu_cangku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÐÇËÞÅÉ´¢²ØÊÒ");

	CBox * box1 = Add_Box();
	box1->add_object("hulu2", 1);	
	box1->set_name( "Æá¹ñ");
		
	CBox * box2 = Add_Box();
	box2->add_object("menghan_yao", 10);	
	box2->set_name( "Æá¹ñ");
		
	CBox * box3 = Add_Box();
	box3->add_object("xxqingxin_san", 10);	
	box3->set_name( "Æá¹ñ");
		
	CBox * box4 = Add_Box();
	box4->add_object("dujing_1", 1);	
	box4->set_name( "Æá¹ñ");	

	add_npc("pub_xiaowuyu");
	
	add_door("ÐÇËÞº£Ð¡Â·", "ÐÇËÞº£Ð¡Â·", "ÐÇËÞÅÉ´¢²ØÊÒ");


/*****************************************************
        set("exits", ([
            "out" : __DIR__"xxroad5",
        ]));
        set("objects", ([
                __DIR__"obj/yanwu" : 1,
                __DIR__"obj/hulu" : 2,
                __DIR__"obj/menghan_yao" : 1,
                __DIR__"obj/xxqingxin-san" : 1,
                "/clone/book/dujing_1"  : 1
        ]));
********************************************/
};


ROOM_END;
