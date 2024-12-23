//hehuating.h

//Sample for room: 荷花厅
//coded by zwb
//data: 2000-11-21

ROOM_BEGIN(CRSuZhou_hehuating);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "荷花厅");
	
	add_npc("pub_shennongdizi");              //add by zdn 2001-07-16
	add_npc("pub_niefeiqong"); 

	add_door("苏州留园", "苏州留园", "苏州荷花厅");
	add_door("苏州古木交诃", "苏州古木交诃", "苏州荷花厅");

	set("long", "荷花厅的主建筑面阔三间，宽敝高爽，厅名取朱熹：“一水方涵碧，千林以变红”之诗意。厅前宽广的平台依临荷池，为夏日赏荷纳凉胜处，故称“荷花厅”。厅后有花台庭院，叠石种树，自成一景。" );
	
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
