//road12.h

//Sample for room: 林间道12
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road12);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道12");

	//add npcs into the room
	add_npc("animal_snake");
	
	CContainer * coin = add_item("coin");
	coin->set_amount(100);

	add_npc("pub_boy");
	add_npc("pub_girl");
	add_npc("pub_girl1");
	if (random(2)==0)
	{
	    add_npc("pub_boy");
		add_npc("pub_girl");
		add_npc("pub_girl1");
	}
	
	add_door("佛山林间道10", "佛山林间道10", "佛山林间道12");

	set("long", "这里是一条林间小道，在树丛中蜿蜒。岭南山林茂密，多产毒虫，各位行路要十分小心。" );
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
