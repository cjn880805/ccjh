//zhulin.h

//Sample for room: 竹林小路
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaLisouth_zhulin);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "竹林小路");

	add_npc("pub_kanzhuren");   // add by zdn 2001-07-13

	add_door("大理城喜州城", "大理城喜州城", "大理城竹林小路");
	add_door("大理城武定镇", "大理城武定镇", "大理城竹林小路");

	set("long", "一条小路穿竹林而过，西南方竹林深处是一大片台夷人聚居的村镇，东北可遥遥望见喜州城的城墙。道路两边竹林茂密，时有台夷人来砍伐。" );
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
