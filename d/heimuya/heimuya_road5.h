//road5.h

//Sample for room: 黄土路5
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路5");
	
	add_npc("heimuya_jiaotu");  //add by zdn 2001-07-20


	add_door("黑木崖厨房", "黑木崖厨房", "黑木崖黄土路5");
	add_door("黑木崖圣姑堂", "黑木崖圣姑堂", "黑木崖黄土路5");
	add_door("黑木崖白虎堂大厅", "黑木崖白虎堂大厅", "黑木崖黄土路5");

	set("long", "你走在一条黄土路上。这里已经是陕西地面了，向南一条黄土大道，两边望不尽的黄土高坡，没有一丝吝啬的绿色。东北隐隐传来流水的声响。");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
                "northeast" : "/d/huanghe/weifen",
                "south"     : __DIR__"road6",
        ]));
********************************************/
};

	

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp