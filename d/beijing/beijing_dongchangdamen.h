//dongchangdamen.h

//Sample for room: 东厂大门
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRBeiJing_dongchangdamen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "东厂大门");

	//add npcs into the room
	add_npc("pub_bing");
	
	add_door("北京东北", "北京东北", "北京东厂大门");

	set("long", "这里就是东厂大门，可以看到里面有许多太监。穿着制服的官兵正在操练，不时地传来呐喊声。如果你不想找死的话，最好还是赶快离开。" );

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
