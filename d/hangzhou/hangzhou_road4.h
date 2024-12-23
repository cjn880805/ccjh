//road4.h

//Sample for room: 杭州青石大道4
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "杭州青石大道4");
	
	add_npc("pub_cunfu");        //add by zdn 2001-07-14


	add_door("杭州青石大道5", "杭州青石大道5", "杭州青石大道4");
	add_door("杭州洪春桥", "杭州洪春桥", "杭州青石大道4");

	set("long","大道上游人，或步行，或乘轿，或骑马。个个喜气洋洋的来游西湖。往南是洪春桥。大道则延伸向东北边。");

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
