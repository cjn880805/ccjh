//road8.h

//Sample for room: 杭州青石大道8
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道8");
	
	add_npc("pub_punk");         //add by zdn 2001-07-14


	add_door("杭州宝石山", "杭州宝石山", "杭州青石大道8");
	add_door("杭州青石大道9", "杭州青石大道9", "杭州青石大道8");
	add_door("杭州青石大道7", "杭州青石大道7", "杭州青石大道8");

	set("long"," 大道上游人，或步行，或乘轿，或骑。个个喜气洋洋的来游西湖。大道延伸向东边和西南边。朝北走便是上宝石山。");

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
