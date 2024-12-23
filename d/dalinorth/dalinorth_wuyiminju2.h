//wuyiminju2.h

//Sample for room: 大理城乌夷民居2
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_wuyiminju2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城乌夷民居2");

	//add npcs into the room
	add_npc("pub_lieren");
	
	add_door("大理城乌蒙村落", "大理城乌蒙村落", "大理城乌夷民居2");

	set("long", "这是一所乌夷族的房屋。乌夷民居的建地和走向讲究依傍四面山势，一般以石为墙和基，以木为梁，结构大致和汉人房屋相仿，皆是平房，石砌围墙。这家院内有一排木架，挂了些山鸡、野鸭、羚羊等猎物，一个猎人正在给猎物剥皮开膛。" );

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
