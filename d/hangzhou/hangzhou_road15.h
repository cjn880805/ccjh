//road15.h

//Sample for room: 杭州青石大道15
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road15);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道15");
	
	
	add_npc("pub_playboy");         // add by zdn 2001-07-14


	add_door("杭州玉皇山脚", "杭州玉皇山脚", "杭州青石大道15");
	add_door("杭州青石大道16", "杭州青石大道16", "杭州青石大道15");
	add_door("杭州青石大道14", "杭州青石大道14", "杭州青石大道15");

	set("long"," 大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。东北和西边各是一条大道。西南边是上玉皇山的山路。    过桥往西走便是白堤了。东北边可通往青石大道");
    

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;
