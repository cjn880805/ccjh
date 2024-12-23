//cangjingshi.h

//Sample for room: 雪山藏经室
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRXueShan_cangjingshi);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "雪山藏经室");

	add_npc("xueshan_daerba");
	
	CBox * box1 = Add_Box();
	box1->add_object("mizong_book", 1);	
	box1->set_name( "漆柜");
		
	CBox * box2 = Add_Box();
	box2->add_object("skin", 1);	
	box2->set_name( "漆柜");	

	CBox * box3 = Add_Box();
	box3->add_object("book_silk", 1);	
	box3->set_name( "漆柜");	

	CBox * box4 = Add_Box();
	box4->add_object("book_stone", 1);	
	box4->set_name( "漆柜");	

	CBox * box5 = Add_Box();
	box5->add_object("book_iron", 1);	
	box5->set_name( "漆柜");	
	
	add_door("雪山寺大殿", "雪山寺大殿", "雪山寺藏经室");

    set("long","这里是雪山寺的藏经室，靠墙是一排书架，摆满了各种拳谱、书籍。大多是当年掌门人鸠摩智翻译的佛经和从少林寺取来的武学典籍。" );

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
