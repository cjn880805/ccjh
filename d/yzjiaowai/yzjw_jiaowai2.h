//yzjw_jiaowai2.h

//Sample for room:  扬州树林2
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai2);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州树林2");

	add_npc("animal_wubushe");
	//add_npc("qiu-wanjia");
	add_npc("pub_bing");      //add by zdn 2001-07-16
	
	CBox * box1 = Add_Box();
	box1->add_object("shuzhi", 1);	
	box1->set_name( "铁柜");
	
	CBox * box2 = Add_Box();
	box2->add_object("shitou", 1);	
	box2->set_name( "铁柜");				

	add_door("扬州树林3","扬州树林3","扬州树林2");
	add_door("扬州草地1","扬州草地1","扬州树林2");

    set("long","扬州郊外的树林，松枝挺拔，乔木横斜。林间小道，逶迤随远。林中蝉鸣厮闹，鸟啼宛转，使你顿时烦意尽消。    地上落了很多树枝石块。");
	

/********************************************************
     set("exits", ([
        "north" : __DIR__"jiaowai1",
        "south" : __DIR__"jiaowai3",
    ]));
    set("objects", ([
        CLASS_D("gaibang")+"/qiu-wanjia": 1,
        __DIR__"obj/shuzhi": 1,
        __DIR__"obj/shitou": 1,
    ]));
//    
    set("outdoors", "yangzhou");
*********************************************************/
};


ROOM_END;
