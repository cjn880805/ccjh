//hole.h

//Sample for room: 大理城芝云洞
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRDaLiNorth_hole);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城芝云洞");

	add_npc("pub_youke");     // add by zdn 2001-07-13

	add_door("大理城长湖", "大理城长湖", "大理城芝云洞");

	set("long", "带着火折进入洞内，迂回蛇行，不久，即见一厅豁然开朗，石钟乳，石笋，石柱，玲珑剔透，斗奇争胜。光照壁影，如月穿晓岩，溪云接水，壁气侵寒，石光滴翠，清幽可爱。");
	
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
