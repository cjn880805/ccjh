//atoubu.h

//Sample for room: 阿头部
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_atoubu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "阿头部");
	
	add_npc("pub_shaonu");
	add_npc("pub_shaonu");   // add by zdn 2001-07-13

	add_door("大理城泸水沿岸", "大理城泸水沿岸", "大理城阿头部");
	add_door("大理城高黎山东坡", "大理城高黎山东坡", "大理城阿头部");
	add_door("大理城易溪部", "大理城易溪部", "大理城阿头部");

	set("long", "阿头部是乌杂蛮的部落，和附近的乌蛮一样，也属于乌夷。这里山高林密，不熟的人轻率进山，很容易迷路丧命。深山对乌夷猎人来说却是聚宝盆，山中野物皆是美味。" );
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
