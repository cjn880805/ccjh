//road7.h

//Sample for room: 林间道7
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road7);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道7");
	
	add_npc("pub_liumangtou");    // add by zdn 2001-07-13
	add_npc("pub_tuguaiguai");

	CBox * box = Add_Box();
	box->add_object("shikuai", 1);	
	box->set_name( "铁柜");	

	add_door("佛山西门", "佛山西门", "佛山林间道7");
	add_door("佛山林间道6", "佛山林间道6", "佛山林间道7");

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
