//milin2.h

//Sample for room:  峨嵋密林2
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_milin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋密林2");

	add_npc("pub_punk");    // add by zdn 2001-07-14
				
	add_door("峨嵋伏虎寺", "峨嵋伏虎寺", "峨嵋密林2");
	add_door("峨嵋解脱坡", "峨嵋解脱坡", "峨嵋密林2");

	set("long","这是黑森森的一片密林，楠木参天，浓阴蔽日。这里西上是报国寺，东边林间隐藏着一座庙宇。");

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
