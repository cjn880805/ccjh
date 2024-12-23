//road9.h

//Sample for room: 杭州青石大道9
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road9);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道9");

	add_npc("pub_playboy");


	add_door("杭州断桥", "杭州断桥", "杭州青石大道9");
	add_door("杭州青石大道8", "杭州青石大道8", "杭州青石大道9");
	add_door("杭州青石大道10", "杭州青石大道10", "杭州青石大道9");

	set("long"," 大道上游人，或步行或乘轿，或骑马。个个喜气洋洋的来游西湖。大道延伸向西边。断桥在大道的西南边。南边则是另一条大道。");

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
