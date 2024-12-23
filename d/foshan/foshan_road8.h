//road8.h

//Sample for room: 林间道8
//coded by zwb
//data: 2000-11-23

ROOM_BEGIN(CRFoShan_road8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "佛山林间道8");

	//add npcs into the room
	add_npc("quanzhen_zhang");
	add_npc("pub_zhangkang");
	
	add_door("佛山东门", "佛山东门", "佛山林间道8");
	add_door("佛山林间道9", "佛山林间道9", "佛山林间道8");

	set("long", "这里是一条林间小道，在树丛中蜿蜒。西面是岭南重镇佛山，东边通向福建泉州。" );

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
