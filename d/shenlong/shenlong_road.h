//road.h

//Sample for room:  神龙教大道
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_road);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教大道");

	add_npc("shenlong_zhang");
	add_npc("pub_longyun");

	add_door("神龙教空地", "神龙教空地", "神龙教大道");
	add_door("神龙教大门", "神龙教大门", "神龙教大道");

	set("long", "这是一条宽敞的大道。全由乱石堆成,显然曾花了不少人力.西边是一片开阔地.");
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
//last, register the room into ../server/RoomSetup.cpp
