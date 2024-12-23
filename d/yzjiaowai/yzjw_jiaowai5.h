//yzjw_jiaowai5.h

//Sample for room:  扬州密林5
//coded by zwb
//data: 2000-11-22

//Note: these two headers must be include
//use macro ROOM_BEGIN(room_name) to declare room
//and use macro ROOM_END end declare
ROOM_BEGIN(CRYZJW_jiaowai5);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "扬州密林5");

	add_npc("animal_dushe");
	add_npc("gaibang_liang");
	add_npc("gaibang_he_bj");
	
	add_door("扬州树林6","扬州树林6","扬州密林5");
	add_door("扬州密林4","扬州密林4","扬州密林5");
	add_door("扬州树林","扬州树林","扬州密林5");
	
    set("long","扬州郊外的茂密树林，阴森可怖。抬头不见天日。这里也是扬州命案发生最多的地方。鸟兽蛇虫游荡不穷。");

/********************************************************
    set("exits", ([
        "east"  : __DIR__"jiaowai4",
        "west"  : __DIR__"jiaowai6",
    ]));
    set("objects", ([
        __DIR__"obj/shuzhi": 2,
        __DIR__"npc/dushe" : 1,
    ]));
//    
*******************************************************/
 
};


ROOM_END;
