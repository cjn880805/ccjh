//huizhen.h

//Sample for room: 燕子坞汇珍园
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_huizhen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "燕子坞汇珍园");
	
	add_npc("murong_yan");        //add by zdn 2001-07-20

	add_door("燕子坞长廊", "燕子坞长廊", "燕子坞汇珍园");

    set("long", "这是燕子坞中最大的花园，遍植江南的奇花异草，香气浓郁。一群彩蝶在花间翩跹飞舞，你不由的痴了，有点乐而忘返。" );
    
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