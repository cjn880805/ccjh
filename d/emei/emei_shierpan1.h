//shierpan1.h

//Sample for room:  峨嵋十二盘1
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_shierpan1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "峨嵋十二盘1");

	add_npc("pub_girldizi");    // add by zdn 2001-07-14
				
	add_door("峨嵋万年庵", "峨嵋万年庵", "峨嵋十二盘1");
	add_door("峨嵋十二盘2", "峨嵋十二盘2", "峨嵋十二盘1");

	set("long","这里石阶陡折多弯，号称「十二盘」。由此西上可达华严顶，东下则到万年庵。");

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
