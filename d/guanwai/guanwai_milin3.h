//milin2.h

//Sample for room: 密林2
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_milin2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "密林2");

	add_npc("pub_liumang");    // add by zdn 2001-07-13 

	set("monster_chance", 20);

	add_door("关外密林1", "关外密林1", "关外密林2");
	add_door("关外黑风口", "关外黑风口", "关外密林2");

	set("long","这是一片茂密的松林，杂乱的生长在倾斜的山坡上。每棵松树都有三四抱粗细，高达十几丈。树冠枝多叶密，将天空完全遮住，因此林内显得有些昏暗。树木之间长着很多灌木杂草，使行走很艰难，据说人参就生长在这些杂草之中。" );
    

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
