//pingdingzhou.h

//Sample for room: 平定州
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_pingdingzhou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "平定州");
	
	add_npc("heimuya_heiyiren");       //add by zdn 2001-07-20


	add_door("黑木崖黄土路2", "黑木崖黄土路2", "黑木崖平定州");
	add_door("黑木崖黄土路3", "黑木崖黄土路3", "黑木崖平定州");

	set("long", "平定州在河北境内，州府不大，但地处要冲，十分重要。往来京城的客商穿梭频繁。但大街上日月教徒横冲直撞，出手抓人，虽近在京畿，却丝毫没将官府放在眼里。");
    

/*****************************************************
    set("exits", ([
        "east" : __DIR__"road3",
        "west" : __DIR__"road2",
    ]));
********************************************/
};


ROOM_END;
