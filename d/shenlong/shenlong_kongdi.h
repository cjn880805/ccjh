//kongdi.h

//Sample for room:  神龙教空地
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRShenLong_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "神龙教空地");

	add_npc("pub_shennongdizi");
	add_npc("shenlong_su");
	
	add_door("神龙教灌木林", "神龙教灌木林", "神龙教空地");
	add_door("神龙教小屋", "神龙教小屋", "神龙教空地");
	add_door("神龙教大道", "神龙教大道", "神龙教空地");
	add_door("神龙教草坪", "神龙教草坪", "神龙教空地");

	set("long", "这是一片空地,四周都是乱石,杂草丛生。北边是一间小屋.南面是深深的灌木林.东面有一条工整的大道,西面是一片草坪.");
    
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