//road3.h

//Sample for room: 林间道3
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道3");

	//add npcs into the room
	add_npc("animal_laofu");
	
	add_door("佛山林间道4", "佛山林间道4", "佛山林间道3");
	add_door("佛山林间道2", "佛山林间道2", "佛山林间道3");

	set("long", "这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山林茂密，多产毒虫，各位行路要十分小心。" );
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
