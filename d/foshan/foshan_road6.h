//road6.h

//Sample for room: 林间道6
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道6");
	
	add_npc("pub_playboy");  // add by zdn 2001-07-13

	CBox * box = Add_Box();
	box->add_object("shikuai", 2);	
	box->set_name( "铁柜");	

	add_door("佛山林间道7", "佛山林间道7", "佛山林间道6");
	add_door("佛山林间道5", "佛山林间道5", "佛山林间道6");

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
