//road3.h

//Sample for room: 黄土路3
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "黄土路3");
	
	add_npc("heimuya_heiyiren");    //add by zdn 2001-07-20


	add_door("黑木崖平定州", "黑木崖平定州", "黑木崖黄土路3");

	add_door("北京大驿道5", "北京大驿道5", "黑木崖黄土路3");

	set("long", "你走在一条黄土路上。这里是山西地界，往东就进入河北了。现在这里不是太平时节，还是快点走吧。");
    

/*****************************************************
         set("outdoors", "heimuya");
        set("exits", ([
                "east" : "/d/city2/ximenwai",
                "west" : __DIR__"pingdingzhou",
        ]));
********************************************/
};


ROOM_END;
