//chahuashan6.h

//Sample for room: 大理城茶花山南
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_chahuashan6);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城茶花山南");

	add_npc("pub_caichanu");   // add by zdn 2001-07-12
	add_npc("dali_huanu");       //add by zdn 2001-07-20

	add_door("大理城大叠水瀑布", "大理城大叠水瀑布", "大理城茶花山南");
	add_door("大理城茶花山5", "大理城茶花山5", "大理城茶花山南");

	set("long", "这儿是茶花山的南面，仍然有大量的茶花盛开着。但显然不如山上的品种好了，都是凡品。" );
	
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
