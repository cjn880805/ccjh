//road6.h

//Sample for room: 黄土路6
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路6");
	
	add_npc("heimuya_heiyiren");       //add by zdn 2001-07-20


	add_door("黑木崖厨房", "黑木崖厨房", "黑木崖黄土路6");
	add_door("黑木崖圣姑堂", "黑木崖圣姑堂", "黑木崖黄土路6");
	add_door("黑木崖白虎堂大厅", "黑木崖白虎堂大厅", "黑木崖黄土路6");

	set("long", "你走在一条黄土路上。陕西的地面，就是看不尽的黄土。向南方望，远远有高山插云，近处好象有个小小村落。隐隐传来犬吠鸡啼，给你长途的奔波带来一丝生气。");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "southeast" : "/d/village/wexit",
                "north"     : __DIR__"road5",
        ]));
********************************************/
};

	

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp