//road2.h

//Sample for room: 黄土路2
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路2");
	
	add_npc("heimuya_jiaotu");       //add by zdn 2001-07-20


	add_door("黑木崖乱石坡", "黑木崖乱石坡", "黑木崖黄土路2");
	add_door("黑木崖平定州", "黑木崖平定州", "黑木崖黄土路2");

	set("long", "你走在一条黄土路上。西南是一个小高岗，地势险恶，客旅断绝。东面隐隐可以看到平定州城。");
    

/*****************************************************
        set("outdoors", "heimuya");
        set("exits", ([
            "southwest" : __DIR__"road1",
            "east" : __DIR__"pingdingzhou",
        ]));
********************************************/
};


ROOM_END;
