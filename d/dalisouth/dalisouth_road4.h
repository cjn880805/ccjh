//road4.h

//Sample for room: 大路4
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_road4);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大路4");

	add_npc("pub_shennongdizi");  //add by zdn 2001-07-13

	add_door("大理城双鹤桥", "大理城双鹤桥", "大理城大路4");
	add_door("大理城天威径", "大理城天威径", "大理城大路4");

	set("long", "一条贯通南北的大路，是由大理城往南边疆土的官道。沿路向南丛林愈发茂密，大片雨林覆盖山岭，此间地势较平坦，大路笔直地连接着北边的大理城和南边的喜州等城镇。" );
	
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
