//xiaolu.h

//Sample for room:  重阳宫小路
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xiaolu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "重阳宫小路");

	add_npc("quanzhen_sun");
	add_npc("quanzhen_tan");

	add_door("重阳宫静修室", "重阳宫静修室", "重阳宫小路");
	add_door("重阳宫后山", "重阳宫后山", "重阳宫小路");

	set("long", "这里是后山上的小路。这条小路好象不是人工刻意修出来的，也许只是以前的采药人踩多了，现出这样一条小路来。");
    
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