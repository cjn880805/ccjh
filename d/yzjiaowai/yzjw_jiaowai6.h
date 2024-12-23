//yzjw_jiaowai6.h

//Sample for room:  扬州树林6
//coded by zwb
//data: 2000-11-22


ROOM_BEGIN(CRYZJW_jiaowai6);


virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州树林6");

//	add_npc("kuai-huosan");	
	add_npc("pub_punk");      //add by zdn 2001-07-16

	CBox * box = Add_Box();
	box->add_object("gourou", 1);	
	box->set_name( "铁柜");
		
	CBox * box1 = Add_Box();
	box1->add_object("hdjiudai", 1);	
	box1->set_name( "铁柜");
		
	CBox * box2 = Add_Box();
	box2->add_object("jitui", 1);	
	box2->set_name( "布袋");	
	
	add_door("扬州密林5","扬州密林5","扬州树林6");
	add_door("扬州草地7","扬州草地7","扬州树林6");

    set("long","扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤随远。林中蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。    地上落了很多树枝石块。");

/********************************************************
    set("exits", ([
        "east" : __DIR__"jiaowai5",
        "west" : __DIR__"jiaowai7",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/kuai-huosan" : 1,
        __DIR__"obj/shitou": 2,
    ]));
//    
*******************************************************/
 
};


ROOM_END;
