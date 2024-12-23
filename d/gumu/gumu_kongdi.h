//kongdi.h

//Sample for room: 古墓空地
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRGuMu_kongdi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "古墓空地");

	add_npc("animal_snake");    //add by zdn 2001-07-13

	add_door("古墓山路", "古墓山路", "古墓空地");
	add_door("古墓树林1", "古墓树林1", "古墓空地");

	set("long","这是终南山山腰处的一块空地，地势平坦。北面一条小路直攀山璧而上，通往是终南山主峰。南边和西边一大片密林，只闻阵阵琴声自林中传出。往北是一条山路。往南和西各有一条小径。");
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
