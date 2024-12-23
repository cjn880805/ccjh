//wuqiku.h

//Sample for room: 侠客岛武器库
//coded by zouwenbin
//data: 2000-11-13
//neiting
ROOM_BEGIN(CRXiaKeDao_wuqiku);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "侠客岛武器库");
	
	CBox * box1 = Add_Box();
	box1->add_object("zhujian", 2);	
	box1->set_name( "漆柜");
		
	CBox * box2 = Add_Box();
	box2->add_object("zhubang", 2);	
	box2->set_name( "漆柜");
			
	CBox * box3 = Add_Box();
	box3->add_object("changbian", 1);	
	box3->set_name( "漆柜");
			
	CBox * box4 = Add_Box();
	box4->add_object("duanjian", 1);	
	box4->set_name( "漆柜");
			
	CBox * box5 = Add_Box();
	box5->add_object("gangdao", 1);	
	box5->set_name( "漆柜");
			
	CBox * box6 = Add_Box();
	box6->add_object("fuchen", 1);	
	box6->set_name( "漆柜");
		
	add_door("侠客岛大厅", "侠客岛大厅", "侠客岛武器库");

    set("long", "这里是侠客岛的武器库，架上摆满了各种武器，任由来岛的武士们挑选。" );

/*****************************************************
         set("exits", ([
                "east" : __DIR__"dating",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 2,
                "/d/city/obj/zhubang" : 2,
                "/d/shaolin/obj/changbian" : 1,
                "/d/city/obj/duanjian" : 1,
                "/d/city/obj/gangdao" : 1,
                "/d/city2/obj/fuchen" : 1
        ]));
********************************************/
};


ROOM_END;
