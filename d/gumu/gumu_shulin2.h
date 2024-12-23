//shulin2.h

//Sample for room: 古墓树林2
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_shulin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓树林2");

	add_npc("animal_dushe");    // add by zdn 2001-07-13

	add_door("古墓树林1", "古墓树林1", "古墓树林2");
	add_door("古墓草地", "古墓草地", "古墓树林2");

	set("long","走在林中，你只闻铮铮琴声，一股淡淡白烟，带着极甜的花香，自密林深处传出。一群乳白色的蜜蜂在你身旁飞来飞去。不论往哪ㄦ走尽是茂密的树林。" );

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
