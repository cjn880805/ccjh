//cangjingshi.h

//Sample for room: ѩɽ�ؾ���
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_cangjingshi);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ѩɽ�ؾ���");

	add_npc("xueshan_daerba");
	
	CBox * box1 = Add_Box();
	box1->add_object("mizong_book", 1);	
	box1->set_name( "���");
		
	CBox * box2 = Add_Box();
	box2->add_object("skin", 1);	
	box2->set_name( "���");	

	CBox * box3 = Add_Box();
	box3->add_object("book_silk", 1);	
	box3->set_name( "���");	

	CBox * box4 = Add_Box();
	box4->add_object("book_stone", 1);	
	box4->set_name( "���");	

	CBox * box5 = Add_Box();
	box5->add_object("book_iron", 1);	
	box5->set_name( "���");	
	
	add_door("ѩɽ�´��", "ѩɽ�´��", "ѩɽ�²ؾ���");

    set("long","������ѩɽ�µĲؾ��ң���ǽ��һ����ܣ������˸���ȭ�ס��鼮������ǵ����������Ħ�Ƿ���ķ𾭺ʹ�������ȡ������ѧ�伮��" );

/*****************************************************
	set("exits", ([
                "southeast" : __DIR__"dating",
	]));

	set("objects", ([
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
		books[random(sizeof(books))] : 1,
                CLASS_D("xueshan")+"/daerba" : 1,
	]));
//        
********************************************/
};


ROOM_END;
