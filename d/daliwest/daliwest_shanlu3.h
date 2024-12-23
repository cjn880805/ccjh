//shanlu3.h

//Sample for room: 山路3
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_shanlu3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "山路3");
	
	add_npc("pub_shaonu");
	add_npc("pub_daoke");       // add by zdn 2001-0-13

	add_door("大理城山路2", "大理城山路2", "大理城山路3");
	add_door("大理城北门", "大理城北门", "大理城山路3");

	set("long", "一条的山路蜿蜒穿行在茂密的森林中，向东不远可达大理国的中心--大理城，西去则进入深山。由于接近大理中心，这条路修整的相当平整，尽管山势崎岖，行路并不困难。" );
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
