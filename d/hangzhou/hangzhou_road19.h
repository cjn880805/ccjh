//road19.h

//Sample for room: 杭州青石大道19
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road19);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道19");

	//add npcs into the room
	add_npc("pub_daoke");
	
	add_door("杭州沿湖大道3", "杭州沿湖大道3", "杭州青石大道19");
	add_door("杭州青石大道20", "杭州青石大道20", "杭州青石大道19");
	add_door("杭州青石大道18", "杭州青石大道18", "杭州青石大道19");

	set("long","大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。大道伸向东和西南两边，往北是另一条大道。" );

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
