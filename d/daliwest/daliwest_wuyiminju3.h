//wuyiminju3.h

//Sample for room: 乌夷民居
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiWest_wuyiminju3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "乌夷民居");
	
	add_npc("pub_shaonu");    /// add by zdn 2001-07-13

	add_door("大理城镇雄", "大理城镇雄", "大理城乌夷民居");
	add_door("大理城祭祀大屋", "大理城祭祀大屋", "大理城乌夷民居");

	set("long", "这是一所乌夷族的房屋。此间正处市镇，四周无山势可依，门口正对巷陌。青石大房，装修颇为不俗，大门是精心雕制的，刻有日、月、虎豹等精美的图案，看来这里是乌撒部的祭祀大屋。" );
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
