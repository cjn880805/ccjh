//road20.h

//Sample for room: 杭州青石大道20
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road20);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道20");
	
	add_npc("pub_poorman");
	add_npc("pub_boy");          // add by zdn 2001-07-14


	add_door("杭州苏堤7", "杭州苏堤7", "杭州青石大道20");
	add_door("杭州青石大道16", "杭州青石大道16", "杭州青石大道20");
	add_door("杭州青石大道19", "杭州青石大道19", "杭州青石大道20");

	set("long"," 大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。大道伸向东西两边，往北是苏堤。");

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
